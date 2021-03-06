%
% Copyright (c) 2015, Yarpiz (www.yarpiz.com)
% All rights reserved. Please read the "license.txt" for license terms.
%
% Project Code: YPML110
% Project Title: Implementation of DBSCAN Clustering in MATLAB
% Publisher: Yarpiz (www.yarpiz.com)
% 
% Developer: S. Mostapha Kalami Heris (Member of Yarpiz Team)
% 
% Contact Info: sm.kalami@gmail.com, info@yarpiz.com
%


%% Load Data
function [xc,yc,seg,movelist]= DBSCAN_cluster(point_simplify)

X=point_simplify;

%% Run DBSCAN Clustering Algorithm

epsilon=0.8;
MinPts=3;
idx=DBSCAN(X,epsilon,MinPts);

region_idx=max(idx);

if region_idx==4    
%% Plot Results

 size_p=size(point_simplify,1);

 point_1=[];
 point_2=[];
 point_3=[];
 point_4=[];

for i=1:size_p
    if idx(i)==1
       point_1=[point_1;point_simplify(i,:)];
    elseif idx(i)==2
       point_2=[point_2;point_simplify(i,:)];
    elseif idx(i)==3
       point_3=[point_3;point_simplify(i,:)];
    elseif idx(i)==4
       point_4=[point_4;point_simplify(i,:)];
    end
end

k_1 = boundary(point_1(:,1),point_1(:,2));
k_2 = boundary(point_2(:,1),point_2(:,2));
k_3 = boundary(point_3(:,1),point_3(:,2));
k_4 = boundary(point_4(:,1),point_4(:,2));

slice_x_1=point_1(:,1);slice_y_1=point_1(:,2);
slice_x_2=point_2(:,1);slice_y_2=point_2(:,2);
slice_x_3=point_3(:,1);slice_y_3=point_3(:,2);
slice_x_4=point_4(:,1);slice_y_4=point_4(:,2);

% Inner boundary
figure 
plot(slice_x_1(k_1),slice_y_1(k_1),'LineWidth',1);hold on;
plot(slice_x_2(k_2),slice_y_2(k_2),'LineWidth',1);hold on;
plot(slice_x_3(k_3),slice_y_3(k_3),'LineWidth',1);hold on;
plot(slice_x_4(k_4),slice_y_4(k_4),'LineWidth',1);hold on
xlabel('X (mm)');
ylabel('Y (mm)');
axis equal

% Outer boundary
xd=[-10.5  10.5 10.5 -10.5 -10.5];
yd=[-20.3 -20.3 20.3  20.3 -20.3];

plot(xd,yd,'LineWidth',1);

%---------------------------
x_hole_1=slice_x_1(k_1)';
y_hole_1=slice_y_1(k_1)';

x_hole_2=slice_x_2(k_2)';
y_hole_2=slice_y_2(k_2)';

x_hole_3=slice_x_3(k_3)';
y_hole_3=slice_y_3(k_3)';

x_hole_4=slice_x_4(k_4)';
y_hole_4=slice_y_4(k_4)';

xc=[xd,NaN,x_hole_1,NaN,x_hole_2,NaN,x_hole_3,NaN,x_hole_4];
yc=[yd,NaN,y_hole_1,NaN,y_hole_2,NaN,y_hole_3,NaN,y_hole_4];

% Diagonal lines£¬change the scan direction
dx = 1;
dy = 1000;
nl = 150; % Could probably calculate this

xe = floor(min(xc)./dx)*dx + (0:(nl-1))*dx;
ye = sort(ceil(max(yc)./dy)*dy - (0:(nl-1))*dy);

xa = xe;
ya = ones(1,nl).*ye(end);
xb = ones(1,nl).*xe(1);
yb = ye(end:-1:1);

xl = [xa; xb];
yl = [ya; yb];
% Zigzag the lines
[xc, yc] = poly2cw(xc, yc);  % Convert polygon contour to clockwise vertex ordering
[xb, yb] = bufferm2('xy', xc, yc, 0.4, 'in'); % If you want some space between zigzag and edge

seg = zeros(0,2);
dirr = true;

for ii = 1:nl
    [isin, inseg] = lineinpolygon(xl(1,ii), yl(1,ii), ...
                    xl(2,ii), yl(2,ii), xb, yb);
    if isin
        if dirr
            seg = [seg; NaN,NaN;inseg(1:end-1,:)];
        else
            seg = [seg; NaN,NaN;inseg(end-1:-1:1,:)];
        end
        dirr = ~dirr;
    end     
end

figure
plot(xc, yc, 'k', seg(:,1), seg(:,2), 'k','LineWidth',1);
xlabel('X (mm)','FontSize',20);
ylabel('Y (mm)','FontSize',20);
zlabel('Z (mm)','FontSize',20);
set(gca,'FontSize',17);
xlim([-11 11])
ylim([-21 21])
axis equal

end
