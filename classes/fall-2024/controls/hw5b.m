% Benjamin Schlueter HW 5b

clear all;
close all;

s = tf('s');

sys1 = 5 * (s + 0.6) / ( s * (1.25*s + 1) * (s + 2) );
sys2 = 3.125 / ( s * (1.25*s + 1) * (s + 2) );
sys3 = 1.6 / ( (s + 0.4) * (s + 0.8) * (s + 1) );

figure();
bodeplot(sys1);

figure();
bodeplot(sys2);

figure();
bodeplot(sys3);

% GM: Gain Margin: PM: Phase Margin, Wcg: Gain Crossover Freq, Wcp: Phase
% Crossover Freq
[GM1, PM1, Wcg1, Wcp1] = margin(sys1)
[GM2, PM2, Wcg2, Wcp2] = margin(sys2)
[GM3, PM3, Wcg3, Wcp3] = margin(sys3)


K1 = 1.23; % want Phase PM = 54 = 59.06 - 4.06
K2 = 0.375; % want PM = 45
K3 = 0.858; % want PM = 30

% Use guess and check

G1 = K1 * sys1;
G2 = K2 * sys2;
G3 = K3 * sys3;

[~, PM1_G, ~, ~] = margin(G1)
[~, PM2_G, ~, ~] = margin(G2)
[~, PM3_G, ~, ~] = margin(G3)






