clear all;
close all;

s = tf('s');

k = 9.8;
b = 119.619;
a = 50;

%Y2 = (400 * k * (s + 50)) / (s^3 + (40 + b)*s^2 + (40*b + 400*k)*s + 20000*k);

Y2 = ((400 / (s*(s+40))) * (k * (s+50)/(s+b))) / (1 + 400 * k / (s*(s+40)) * (s+50) / (s + b));

figure();
step(Y2);

% [max_signal, max_index] = max(Y2);
gain = getPeakGain(Y2);
fprintf('Max value (peak overshoot) of Y2: %.6f\n', gain);

% 2

Gp = (s + 30) / ((s + 6) * (s + 12) * (s + 18) * (s + 24));

Kp = 6000;
PID_controller = Kp;
ClosedLoop = feedback(PID_controller * Gp, 1);
figure()
step(ClosedLoop);
