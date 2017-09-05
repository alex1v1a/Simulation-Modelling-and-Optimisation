function[sol,val]=tsp(sol,~);
global distMatrix points dist; %Globals -

%Please input a speed for the runner
speed=3;

%Initial setup
dist=0;
points=-1000;
%First position assigned
loc1=1;
numvars=size(sol,2)-1;

%Start Loop 
for z=1:numvars
    %Current location assigned popyt
    loc2=sol(z);
    %New distance added to the total
    dist=dist+distMatrix(loc1,loc2);
    if loc2==1
        %Completed cycle, location semetric - and exit
        break
    %Add points to runner based on target - 9 points each worth 2,3,4 resp.
    elseif 0<loc2 && loc2<10
        points=points+2; %location 01-09
    elseif 9<loc2 && loc2<19
        points=points+3; %location 10-18
    else
        points=points+4; %location 19-27
    end
    %Update position and run cycle again until reached end
    loc1=loc2;
end                            

%Check time limit exceeded
time=dist/speed; %Yay I went to highschool!
if time>3600 %T in secconds obviously
    %Penality applied
    points=points-(time-3600)/30*2; 
end

%Return points total - Final score
val=points;
end


