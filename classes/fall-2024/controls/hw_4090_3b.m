% Benjamin Schlueter ECE 4090 HW 3B

% clean up
clear all;
close all;

% 1

s = tf('s'); % function to create special transfer function variable

Gp1 = (s + 1) / (s * (s - 1) * (s + 6));

figure();
rlocus(Gp1); % matlab function for root locus plot

% 2 

Gp2 = (s + 2) / (s * (s - 4));

figure();
rlocus(Gp2);