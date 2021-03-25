function [anyIn, inSegment, outSegment] = lineinpolygon(x1, y1, x2, y2, xv, yv)
%LINEINPOLYGON Looks for segments of a line within a polygon
%
% [anyIn, inSegment, outSegment] = lineinpolygon(x1, y1, x2, y2, xv, yv)
%
% This program looks at a straight line and a closed polygon and determines
% which segments of the line are located inside the polygon.
%
% Input variables:
%
%   x1:         x coordinate of line starting point
%
%   y1:         y coordinate of line starting point
%
%   x2:         x coordinate of line ending point
%
%   y2:         y coordinate of line ending point
%
%   xv:         x coordinates of vertices of polygon
%
%   yv:         y coordinates of vertices of polygon
%
% Output variables:
%
%   anyIn:      true if any portion of the line is located in the polygon
%
%   inSegment:  n x 2 [x y] array of line segments located inside the
%               polygon.  Segments are separated by NaNs.
%
%   outSegment: n x 2 [x y] array of line segments located outside the
%               polygon.  Segments are separated by NaNs.

% Copyright 2005 Kelly Kearney

%-----------------------------
% Check if line is moving left
% to right or vice versa
%-----------------------------

isLeftToRight = x1 < x2;

if iscell(xv)
    [xv, yv] = polyjoin(xv, yv);  % Convert line or polygon parts from cell arrays to vector form
end

%-----------------------------
% Find intersection points
%-----------------------------

[xint, yint] = polyxpoly([x1 x2], [y1 y2], xv, yv, 'unique');
intPoints = [xint yint];
if ~isempty(intPoints)
    if isLeftToRight
        intPoints = sortrows(intPoints, 1);
    else
        intPoints = flipud(sortrows(intPoints, 1));
    end
end
nsegments = size(intPoints,1) + 1;

%-----------------------------
% Divide line into in-segemnts
% and out-segments
%-----------------------------

xin = [];
yin = [];
xout = [];
yout = [];

segmentIsIn = inpolygons(x1, y1, xv, yv);

for iseg = 1:nsegments
    if iseg == 1
        xseg1 = x1;
        yseg1 = y1;
    else
        xseg1 = intPoints(iseg-1,1);
        yseg1 = intPoints(iseg-1,2);
    end
    if iseg == nsegments
        xseg2 = x2;
        yseg2 = y2;
    else
        xseg2 = intPoints(iseg,1);
        yseg2 = intPoints(iseg,2);
    end
    if segmentIsIn
        xin = [xin xseg1 xseg2 NaN];
        yin = [yin yseg1 yseg2 NaN];
    else
        xout = [xout xseg1 xseg2 NaN];
        yout = [yout yseg1 yseg2 NaN];
    end
    segmentIsIn = ~segmentIsIn;
end

anyIn = ~isempty(xin);
inSegment = [xin' yin'];
outSegment = [xout' yout'];