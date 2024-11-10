% Benjamin Schlueter ECE 4090 HW 3B

% clean up
clear all;
close all;

% 1

s = tf('s'); % function to create special transfer function variable

G_p = (s + 1) / (s * (s - 1) * (s + 6));

rlocus(G_p); % matlab function for root locus plot