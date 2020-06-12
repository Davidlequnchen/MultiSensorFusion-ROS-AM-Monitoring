s = tf('s');
K = 44.348; %system DC gain
Tw = 0.013638;
zeta = 0.361;
% system transfer function(second order, underdamped)
sys = K/(Tw^2*s^2+2*zeta*Tw*s+1);
controlSystemDesigner(sys);
