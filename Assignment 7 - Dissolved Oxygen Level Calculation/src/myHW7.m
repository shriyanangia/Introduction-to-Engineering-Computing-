%---------------------------------------------------------------------------
% Name: Shriya Nangia
% Date: May 8 2020
% Filaname: myHW7.m
% Description: Code to estimate how long it takes the oxygen level to 
%              return to the initial level(baseline) after a bolus injection 
%              of a pollutant is added to the river stream.
%---------------------------------------------------------------------------

clear, close all
clc

%Opening text file, reading and saving values in a matrix,A
fileID = fopen('PollutionData.txt','r');
formatSpec = '%f';
A = fscanf(fileID,formatSpec);

%Assigning values saved in matrix A to their respective parameters
%Converting values to ensure uniform units are being used across parameters
D0 = A(1);
L0 = A(2);
S = A(3)*(3600/(30.48^2));
H = A(4);
V = A(5)*3600;
kd = A(6);

%Setting the time frame to simulate 30‐minute increments for 250 hours
t = 0:0.5:250;
%Calling the reaeration function in order to estimate the reaeration constant, kr 
kr = reaeration(V,S,H);
%Calling the deOxygen function to calculate dissolved oxygen deficit, D
D = deOxygen(kd,L0,kr,t,D0);
%Plotting the dissolved oxygen deficit, D against time, t 
plot(t,D)
title('Dissolved oxygen deficit against Time')
xlabel('Time after pollutant added(hrs)')
ylabel('Dissolved oxygen deficit(mg/l)')
grid on

%Determine and report the time(in hours)for the oxygen deficit to return to the initial deficit level
Yindice = find(D <= 5);
Xindice = t(Yindice(2));
reportTime1 = ["The oxygen deficit returns to the initial deficit level at:", Xindice, "hours"];
disp(reportTime1)

%Determine and report the time(in hours) for the oxygen deficit to return to 80% of the initial deficit level
%In order to find 80% of the initial deficit level, a larger time frame,t2, is
%needed as this occurs past the 250hrs mark
t2 = 0:0.5:300;
D = deOxygen(kd,L0,kr,t2,D0);
yindice = find(D <= 4);
xindice = t2(yindice(1));
reportTime2 = ["The oxygen deficit returns to 80% of the initial deficit level at: ", xindice, "hours"];
disp(reportTime2)

%Create new figure window with handle 2
figure(2);  
t = 0:0.5:250;
%Defining the six flow velocities between 100ft∙hr‐1 and 250ft∙hr‐1,
%inclusive and saving them in a matrix, z
z = linspace(100,250,6);

%For each flow velocity, calculating the new reaeration constant, kr and dissolved oxygen deficit, D
%For each flow velocity determining the time(timeToBaseline) to return to
%initial(baseline) pollutant level,D0
V1 = z(1);
kr1 = reaeration(V1,S,H);
D1 = deOxygen(kd,L0,kr1,t,D0);
Y1indice = find(D1 <= 5);
X1indice = t(Y1indice(2));
timeToBaseline(1) = X1indice;

V2 = z(2);
kr2 = reaeration(V2,S,H);
D2 = deOxygen(kd,L0,kr2,t,D0);
Y2indice = find(D2 <= 5);
X2indice = t(Y2indice(2));
timeToBaseline(2) = X2indice;

V3 = z(3);
kr3 = reaeration(V3,S,H);
D3 = deOxygen(kd,L0,kr3,t,D0);
Y3indice = find(D3 <= 5);
X3indice = t(Y3indice(2));
timeToBaseline(3) = X3indice;

V4 = z(4);
kr4 = reaeration(V4,S,H);
D4 = deOxygen(kd,L0,kr4,t,D0);
Y4indice = find(D4 <= 5);
X4indice = t(Y4indice(2));
timeToBaseline(4) = X4indice;

V5 = z(5);
kr5 = reaeration(V5,S,H);
D5 = deOxygen(kd,L0,kr5,t,D0);
Y5indice = find(D5 <= 5);
X5indice = t(Y5indice(2));
timeToBaseline(5) = X5indice;

V6 = z(6);
kr6 = reaeration(V6,S,H);
D6 = deOxygen(kd,L0,kr6,t,D0);
Y6indice = find(D6 <= 5);
X6indice = t(Y6indice(2));
timeToBaseline(6) = X6indice;

%Plotting in first subplot the dissolved oxygen, D(t) against time after
%pollutant added for the 6 flow velocities
subplot(2,1,1)
plot(t,D1,'b-',t,D2,'g--',t,D3,'r.',t,D4,'c-',t,D5,'m--',t,D6,'y.');
legend('V1=100', 'V2=130', 'V3=160', 'V4=190', 'V5=220', 'V6=250');
title('Dissolved oxygen against time after pollutant added for 6 flow velocities')
xlabel('Time after pollutant added(hrs)')
ylabel('Dissolved oxygen deficit(mg/l)')

%Plotting in the second subplot the time to return to initial(baseline)
%pollutant level for each of the 6 flow velocities 
subplot(2,1,2)
plot(z,timeToBaseline,'o:g')
title('Time to return to baseline  pollutant level against river flow velocity')
xlabel('River flow velocity(ft/hr)')
ylabel('Time to Baseline(hrs)')

%Extra credit assignment
%Producing an animated plot of the dissolved oxygen deficit 
%versus time for each time step as specified by the user
figure(3);
animatedGraph()

%Closing the text file
fclose(fileID);

function kr = reaeration(velocity,diffusivity, depthOfFlow)
    % This function estimates the reaeration constant kr.
    % The function has three input parameters and returns the reaeration
    % constant,kr after calculation based on the given equation
    
    kr = ((velocity*diffusivity)^0.5)/(depthOfFlow^1.5);
    
end

function D = deOxygen(kd,L0,kr,t,D0)
    %This function calculates the dissolved oxygen deficit based on the
    %given equation. 
    % It takes in 4 input parameters and returns the dissolved oxygen
    % deficit,D
        
    D = (((kd*L0)/(kr-kd))*(exp(-kd*t)-exp(-kr*t)))+(D0*exp(-kr*t));
        
end

function animatedGraph()
    %Extra Credit Function
    %This function gathers 3 inputs from the user: the input file name, number
    %of hours the simulation should run for and the increment interval as a multiple of hours
    %The input file should have exactly 6 values
    %The function function uses the newly imported values to compute the
    %reaeration constant and dissolved oxygen deficit
    %The function runs the simulation for the given amount of time and produces an animated plot
    %of the dissolved oxygen deficit versus time for each time step as specified by the user
    %The animated figure renders completely in less than 30 seconds
    
    fileName = input('Enter file name: ' , 's')
    fileIn = fopen(fileName,'r');
    formatSpec = '%f';
    inputVariables = fscanf(fileIn,formatSpec);
    if size(inputVariables) ~= 6
        disp("The file is not in the expected format.")
    else 
        D0 = inputVariables(1);
        L0 = inputVariables(2);
        S = inputVariables(3)*(3600/(30.48^2));
        H = inputVariables(4);
        V = inputVariables(5)*3600;
        kd = inputVariables(6);
        prompt1 = 'Please enter the number of hours the simulation should run for.';
        duration = input(prompt1)
        prompt2 = 'Please enter the increment interval as a multiple of hours';
        incrementInterval = input(prompt2)
        t = 0:incrementInterval:duration;
        kr = reaeration(V,S,H);
        D = deOxygen(kd,L0,kr,t,D0);
        
        curve = animatedline;
        grid on;
        pointsToPlot = duration/incrementInterval;
        pauseVal = 30/(pointsToPlot*3600);
        title('Dissolved oxygen deficit against Time')
        xlabel('Time after pollutant added(hrs)')
        ylabel('Dissolved oxygen deficit(mg/l)')
        for i=1:length(t)
            addpoints(curve,t(i),D(i));
            drawnow limitrate
            pause(pauseVal);
        end
    end
    fclose(fileIn);
   
end
