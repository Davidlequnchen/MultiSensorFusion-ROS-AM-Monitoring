function [in, index] = inpolygons(x,y,xv,yv)
% INPOLYGONS Performs inpolygon on multiple polygons, holes possible
%
%   in = inpolygons(x,y,xv,yv)
%   [in, index] = inpolygons(x,y,xv,yv)
%
% This function is an extension of Matlab's inpolygon function.  It allows
% the input polygon vertices to describe multiple NaN-delimited polygons.
% The polygons can also include holes.
%
% Input variables:
%
%   x:      x coordinates of points, any dimensions
%
%   y:      y coordinates of points, same dimensions as x
%
%   xv:     x coordinates of polygon vertices, vector.  Separate polygons
%           by NaN.  List vertices of polygons clockwise and holes
%           counterclockwise (use ispolycw to test this).  Holes must
%           immediately follow the polygon with which they are associated.
%
%   yv:     y coordinates of polygon vertices, vector same length and
%           format as xv.  
%
% Output variables:
%
%   in:     matrix in the same size as x and y where in(p,q) = 1 if the
%           point (x(p,q), y(p,q)) is inside any of the polygons defined by
%           xv and yv    
%
%   index:  cell array with the same dimensions as x and y holding the
%           indices of the polygons in which each point was found (0 for
%           point outside all polygons).  
%
% Example:
%
% xv = [1 1 7 7 1 NaN 2 3 3 2 2 NaN 5 6 5 5 NaN 7 8 9 8 7];
% yv = [1 4 4 1 1 NaN 2 2 3 3 2 NaN 2 2 3 2 NaN 8 9 8 7 8];
% x = 10 * rand(20,10); y = 10 * rand(20,10);
% [in, index] = inpolygons(x, y, xv, yv);
% index = cell2mat(index);  % No overlapping polygons allows this.
% [f, v] = poly2fv(xv, yv);
% hold on;
% patch('Faces', f, 'Vertices', v, 'FaceColor', [.9 .9 .9], ...
%       'EdgeColor', 'none');
% plot(x(in), y(in), 'r.', x(~in), y(~in), 'b.');
% plot(x(index==1), y(index==1), 'go', x(index==2), y(index==2), 'mo');


% Copyright 2005 Kelly Kearney

%-----------------------------
% Check inputs
%-----------------------------

if size(x) ~= size(y)
    error('x and y must have the same dimensions');
end

if ~isvector(xv) || ~isvector(yv) || length(xv) ~= length(yv)
    error('xv and yv must be vectors of the same length');
end

%-----------------------------
% Find number of and starting
% indices of polygons
%-----------------------------

[xsplit, ysplit] = polysplit(xv, yv);
isCw = ispolycw(xsplit, ysplit);
mainPolyIndices = find(isCw);
nHolesPer = diff([mainPolyIndices;length(isCw)+1]) - 1;

%-----------------------------
% Test if points are in each
% polygon
%-----------------------------

originalSize = size(x);
x = x(:);
y = y(:);

isIn = zeros(length(x), length(mainPolyIndices));
for ipoly = 1:length(mainPolyIndices)
    isInMain = inpolygon(x, y, xsplit{mainPolyIndices(ipoly)}, ysplit{mainPolyIndices(ipoly)});
    if nHolesPer(ipoly) > 0
        isInHole = zeros(length(x), nHolesPer(ipoly));
        for ihole = 1:nHolesPer(ipoly)
            isInHole(:,ihole) = inpolygon(x, y, xsplit{mainPolyIndices(ipoly)+ihole}, ysplit{mainPolyIndices(ipoly)+ihole});
        end
        isIn(:,ipoly) = isInMain & ~any(isInHole,2);
    else
        isIn(:,ipoly) = isInMain;
    end
end

in = any(isIn, 2);
in = reshape(in, originalSize);

if nargout == 2

    index = num2cell(zeros(size(x)));
    for ipoint = 1:length(x)
        loc = find(isIn(ipoint,:));
        if ~isempty(loc)
            index{ipoint} = loc;
        end
    end

    index = reshape(index, originalSize);
end