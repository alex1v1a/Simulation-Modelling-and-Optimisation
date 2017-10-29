close all; clc; warning('off','all'); %Turn off warnings etc (annoying)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Tension of tower

MassMars = 6.4185*10^23; %Kg - Googled to Nasa (National Aeronautics and Space Administration)
RadiusMars = 3396.2*1000; %m - Googled to Nasa (National Aeronautics and Space Administration) (Equatorial Radius)
R=RadiusMars:1000:6.76*10^7; %Distance from the centre of Mars

MeanRadiusPhobos = 11.1*1000; %m - Googled to Nasa (National Aeronautics and Space Administration)
CrossSection = 300; 

Period = 24*60*60; % Orbit is 1 day and 40 min (24hrs 40min) close to earth so take 24 hours as the given day (Google common knowledge)
Angularfrequency = 2*pi/Period; %Frequency(Omega) = 2pi/T (Period)

SF = 3;
delta = 5; %Delta is defined as the section height on the orbital tower at Phobos orbit
CarbonNanoDensity = 1.6*10^(-3); %Unit -  Kg/m^3 Carbon Fiber Nano is high strength to weight ratio, logical choice for tower material
UGC = 6.674*10^-11; %N.m2/kg2 Universal Gravitational Constant
SeperationDist = 5980*1000; %m (6000)(9376km - 3396) % Unit - m (6000)(9376km - 3396) %Distance between surfaces Phobos to Mars

%Apply the traverse wave equation.
%This is the formula for calculating the tension, as provided in the Tower equations - student.pdf
%Please note both ends of the orbital tower remain stationary

%R is the distance from the centre of Mars, rm is the radius of Mars, M is the mass of Mars, œâ is the orbital frequency of Mars, 
%G is the gravitational constant and œÅA is the mass of the volume element and is assumed to be constant

Tension = delta*CrossSection*(Angularfrequency^2/2.*(-R.^2.+RadiusMars^2)+UGC*MassMars*((-1./R)+(1/RadiusMars)));

%Plotting the tension with height will create a curve starting at zero, 
%reaching a maximum at the areostationary point and declining to zero at the end of the tower

%Plot Tension Graph
figure(1)
plot(R,Tension)

title('TENSION OF TOWER');
xlabel('Height of Tower - Meters'); ylabel('Tension of Tower - Newtons');

indexmin = find(min(Tension) == Tension); %Min tension of the tower at aerostationary orbit
xmin = round((R(indexmin)),3,'significant'); %Min height of tower
ymin = round((Tension(indexmin)),3,'significant');  

indexmax = find(max(Tension) == Tension); %Max height of tower
xmax = round((R(indexmax)),3,'significant');
ymax = round(Tension(indexmax),3,'significant'); %Max tension of tower at aerostationary orbit

strmin = ['Max Height of the Tower = ',num2str(xmin),'m'];  
text(xmin,ymin,strmin,'HorizontalAlignment','right');

strmax = ['Max Tension on the Tower = ',num2str(ymax),'N'];
text(xmax,ymax,strmax,'HorizontalAlignment','left');

%The net force is zero at every point of the orbital tower, therefore tension equals gravitational force less centrifugal force.  

%Geostationary location is at 2√ó10e7m 
%Height step is 1000 meters
%Maximum Tension on the Tower = 1.47√óe10N

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Calculation for the speed of the wave.

H=SeperationDist+RadiusMars; 
Tension2=delta*CrossSection*(Angularfrequency^2/2.*(-H^2+RadiusMars^2)+UGC*MassMars*((-1./H)+(1/RadiusMars))); %Tension of the tower 

%TENSION GIVES C^2 - C-square. By simulating the tension, we can find the geostationary point or the lookout station of the OT.
C_square = Tension2/CarbonNanoDensity; %C^2 is the tension divided by the mass of the volume element, speed of the wave on the tower, C_square = 7.3524e+12 

%In order to solve this, it is required to convert the second order differential equation to linear algebra. 
%This has been done to perform the Crank-Nicolson method as the stability does not depend on "r" parameter.
%3.1.2 Crank-Nicolson Implicit Method Pg 18-20 pdenum.pdf

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Displacement of the tower - Wave Transformation

%The traverse wave equation contains two displacement parameters or entities. The wave will essentially travel along the tower
%This makes the first parameter is the normal to the direction of propagation. The second parameter is the actual displacement along the orbital tower. 
%There are two major forces are acting on the orbital tower. One force is centrifuge force and the other is gravitational force.
%Propagative wave is assumed as 306 seconds, and the orbital period of Phobos is 90.25 times the period of the wave, wave speed is 0.1356 m/s.

PhobosPeriod = 7*60*60+39*60;  %Phobos peroid is 7 hours and 39 minutes

%Time step is 1 second, and the height step is set as 1000 meters
%h is the length of a time step and k is the length of a height step
k=1; %Time inteval 1 second
j = 6000; %Displacement Interval
h = 1000; %Displacement unit
i = 306; %Time interval

r = C_square*((h^2)/(k^2)); %r = c2h2/k2 and ui is a column vector of all the displacements of the tower at the ith time step

%Transformation of the second order differential equation, required to rearrange the linearized equation by terming the metrics A, B and C
%Ì†µÌ∞¥√óÌ†µÌ±à(Ì†µÌ±ñ+1)=Ì†µÌ∞µ√óÌ†µÌ±à(Ì†µÌ±ñ)+Ì†µÌ∞∂√óÌ†µÌ±à(Ì†µÌ±ñ‚àí1) 

%Diagonal significant matrices
A = diag((1+r)*ones(1,j+1))+diag((-r/2)*ones(1,j),1)+diag((-r/2)*ones(1,j),-1);  
B = diag((2-r)*ones(1,j+1))+diag((r/2)*ones(1,j),1)+diag((r/2)*ones(1,j),-1);
C = -ones(j+1,1);

%ui,j is the displacement at the ith time step and the jth height step up the tower
Uij = zeros(j+1,1);
Uij(:,2)=Uij;h;

for n=2:i
    Uij(:,n+1)=(B*Uij(:,n)+C.*Uij(:,n-1))\A;  %Transformed wave equation
end
%UL(:,0) and U1(:,1) are zero, so U1(:,n+1) will be zero after calculation

%Mesh plot of tower with no external forces
figure(2)
mesh(Uij)

title('TOWER WITH NO EXTERNAL FORCE(s) APPLIED ');
ylabel('Height Of Tower - Meters'); xlabel('Time  - Seconds'); zlabel('Displacement Affecting the Tower - Meters');

%Mesh plot ranged 0 to 400 seconds - time domain
%Height domain ranged 0 to 6000 steps 
%6000 steps will represent 6 000 000 meters

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Displacement Force on the Orbital Tower (Wave Equation)

X = 2*MeanRadiusPhobos; %Diameter of the phobos
Lamda = 6*MeanRadiusPhobos;
N=round((SeperationDist/Lamda),3,'significant');
T1=PhobosPeriod/N;
w=2*pi/T1; %Frequency Omega
U = zeros(j+1,1); %U is the sideways displacement of the tower

%Applied force =  Ì†µÌ±ã√ósin (Ì†µÌ±ä√óÌ†µÌ±õ√óÌ†µÌ±ò) 
%X  = 4 times the radius of Phobos  
%W = Sine wave angular frequency (90 times of phobos frequency) 
%N  = Time steps  
%K  = Time step unit  

U(:,2)=U+X*sin(w*2*k);

for n=2:i
    U(:,n+1)=(B*U(:,n)+C.*U(:,n-1))\A+X*sin(w*n*k);
end

%Mesh plot with applied external forces - Energy calculation
figure(3)
mesh(U);

title('TOWER WITH EXTERNAL FORCE(s) APPLIED');
ylabel('Height Of Tower - Meters'); xlabel('Time  - Seconds'); zlabel('Displacement Affecting the Tower - km');

%Energy Produced = (1/2)√óÌ†µÌ±ö√óÌ†µÌ±§‚àóÌ†µÌ∞¥2√óÌ†µÌ∞º  

%Orbital Tower Section Mass =  Ì†µÌ±ö = 2,500,000Kg 
%Angular Velocity = Ì†µÌ±§ = 0.205Rad/s 
%Amplitude of the Wave = Ì†µÌ∞¥ = 44400m 
%Wave Propagation Velocity = Ì†µÌ∞º = 0.1356 m/s

%1.4088e11 Joules for the height of the tower at 6000km = Total Energy 614√ó1.4088e11 Joules  

%Total Energy = 9.65e13 Joules



 