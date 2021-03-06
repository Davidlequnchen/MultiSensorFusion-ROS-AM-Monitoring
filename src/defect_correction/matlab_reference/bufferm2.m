function [out1,out2] = bufferm2(varargin)
%BUFFERM2 Computes buffer zone around a polygon
%
% [latb,lonb] = bufferm2(lat,lon,dist,direction)
% [latb,lonb] = bufferm2(lat,lon,dist,direction,npts)
% [latb,lonb] = bufferm2(lat,lon,dist,direction,npts,outputformat)
% [xb,  yb]   = bufferm2('xy',x,y,dist,direction,npts,outputformat)
%
% This function was originally designed as a replacement for the Mapping
% Toolbox function bufferm, which calculates a buffer zone around a
% polygon. The original bufferm function had some serious bugs that could
% result in incorrect buffer results and/or errors, and was also very slow.
% As of R2006b, those bugs have been fixed.  However, this version still
% maintains a few advantages over the original: 
%
%   - Can be applied to polygons in either geographical space (as in
%   bufferm) or in cartesian coordinates.
%
%   - Better treatment of polygon holes.  The original function simply
%   filled in all holes; this version trims or pads holes according to the
%   buffer width given.
%
% Input and output format is identical to bufferm unless the 'xy' option is
% specified, so it can be used interchangeably.
%
% Input variables:
%
%   lat:            Latitude values defining the polygon to be buffered.
%                   This can be either a NaN-delimited vector, or a cell
%                   array containing individual polygonal contours (each of
%                   which is a vector). External contours should be listed
%                   in a clockwise direction, and internal contours (holes)
%                   in a counterclockwise direction.
%
%   lon:            Longitude values defining the polygon to be buffered.
%                   Same format as lat. 
%
%   dist:           Width of buffer, in degrees of arc along the surface
%                   (unless 'xy' is used, in which case units correspond to
%                   x-y coordinates)
%
%   direction:      'in' or 'out'
%
%   npts:           Number of points used to contruct the circles around
%                   each polygon vertex.  If omitted, default is 13. 
%
%   outputformat:   'vector' (NaN-delimited vectors), 'cutvector'
%                   (NaN-clipped vectors with cuts connecting holes to the
%                   exterior of the polygon), or 'cell' (cell arrays in
%                   which each element of the cell array is a separate
%                   polygon), defining format of output.  If omitted,
%                   default is 'vector'.
%
%   'xy':           If first input is 'xy', then data will be assumed to
%                   lie on a cartesian plane rather than on a sphere.  Use
%                   x and y coordinates as first two inputs rather than lat
%                   and lon.  Units of x, y, and distance should be the
%                   same.
%
% Output variables:
%
%   latb:           Latitude values for buffer polygon
%
%   lonb:           Longitude values for buffer polygon
%
% Example:
%
%   load conus
%   tol = 0.1; % Tolerance for simplifying polygon outlines
%   [reducedlat, reducedlon] = reducem(gtlakelat, gtlakelon, tol);
%   dist = 1;  % Buffer distance in degrees
%   [latb, lonb] = bufferm2(reducedlat, reducedlon, dist, 'out');
%   figure('Renderer','painters')
%   usamap({'MN','NY'})
%   geoshow(latb, lonb, 'DisplayType', 'polygon', 'FaceColor', 'yellow')
%   geoshow(gtlakelat, gtlakelon,...
%                       'DisplayType', 'polygon', 'FaceColor', 'blue')
%   geoshow(uslat, uslon)
%   geoshow(statelat, statelon)
%
% See also:
%   
%   bufferm, polybool
% Copyright 2010 Kelly Kearney
%---------------------------
% Check input
%---------------------------
narginchk(3,7);
% Determine if geographic or cartesian
if ischar(varargin{1}) && strcmp(varargin{1}, 'xy')
    geo = false;
    param = varargin(2:end);
else
    geo = true;
    param = varargin;
end
% Set defaults if not provided as input
nparam = length(param);
if geo
    [lat, lon, dist] = deal(param{1:3});
else
    [lon, lat, dist] = deal(param{1:3}); % lon = x, lat = y for mental clarity, will switch back at end
end
if nparam < 4
    direction = 'out';
else
    direction = param{4};
end
if nparam < 5
    npts = 13;
else
    npts = param{5};
end
if nparam < 6
    outputformat = 'vector';
else
    outputformat = param{6};
end
% Check format and dimensions of input
if ~ismember(direction, {'in', 'out'})
    error('Direction must be either ''in'' or ''out''.');
end
if ~ismember(outputformat, {'vector', 'cutvector', 'cell'})
    error('Unrecognized output format flag.');
end
if ~isnumeric(dist) || numel(dist) > 1
    error('Distance must be a scalar.')
end
if ~isnumeric(npts) || numel(npts) > 1
    error('Number of points must be a scalar.')
end
if iscell(lat)
    for il = 1:numel(lat)
        if ~isvector(lat{il}) | ~isvector(lon{il}) | ~isequal(length(lat{il}), length(lon{il}))
            error('Lat (or x) and lon (or y) must be vectors or cells of vectors with identical dimensions');
        end
        lat{il} = lat{il}(:);
        lon{il} = lon{il}(:);
    end
else
    if ~isvector(lat) || ~isvector(lon) || ~isequal(length(lat), length(lon))
        error('Lat (or x) and lon (or y) must be vectors or cells of vectors with identical dimensions');
    end
    lat = lat(:);
    lon = lon(:);
end
%---------------------------
% Set up ability to call 
% polybool-related functions
% directly
%---------------------------
    
msg = ['Could not find copies of vectorsToGPC.m (%s) and/or ', ...
       'mex function gpcmex (%s).', ...
       'The proper files should be found in the ', ...
       'toolbox/map/map/private folder under the ', ...
       'directory where Matlab is installed'];
mappath = fullfile(matlabroot, 'toolbox', 'map', 'map', 'private');
v2gpcpath = fullfile(mappath, 'vectorsToGPC.m');
vfgpcpath = fullfile(mappath, 'vectorsFromGPC.m');
Gpc = dir(fullfile(mappath, 'gpcmex*'));
if length(Gpc) < 1
    error('bufferm2:gpcmex', 'Could not find gpcmex in default location (%s)', mappath);
end
if length(Gpc) > 1
    warning('Mutiple gpcmex files found; using %s', Gpc(1).name);
    Gpc = Gpc(1);
end
gpcmexpath = fullfile(mappath, Gpc.name);
if ~exist(vfgpcpath, 'file') || ~exist(gpcmexpath, 'file')
    error('multiplepolyint:privatepath', msg, v2gpcpath, gpcmexpath);
end
vectorsToGPC = function_handle(v2gpcpath);
vectorsFromGPC = function_handle(vfgpcpath);
gpcmex = function_handle(gpcmexpath);
%---------------------------
% Split polygon(s) into 
% separate faces 
%---------------------------
p = vectorsToGPC(lon, lat);
%---------------------------
% Create buffer shapes
%---------------------------
if geo
    [latc, lonc] = calccircgeo(cat(1, p.y), cat(1, p.x), dist, npts);
    pc = struct('x', lonc, 'y', latc, 'ishole', num2cell(false(size(latc))));
else
    [xc, yc] = calccirccart(cat(1, p.x), cat(1, p.y), dist, npts);
    pc = struct('x', xc, 'y', yc, 'ishole', num2cell(false(size(xc))));
end
if geo
    [latr, lonr] = deal(cell(size(p)));
    for ii = 1:length(p)
        [latr{ii}, lonr{ii}] = calcrecgeo(p(ii).y, p(ii).x, dist);
    end
    latr = cat(2, latr{:});
    lonr = cat(2, lonr{:});
    pr = struct('x', lonr, 'y', latr, 'ishole', num2cell(false(size(latr))));
else
    [xr, yr] = deal(cell(size(p)));
    for ii = 1:length(p)
        [xr{ii}, yr{ii}] = calcreccart(p(ii).x, p(ii).y, dist);
    end
    xr = cat(2, xr{:});
    yr = cat(2, yr{:});
    pr = struct('x', xr, 'y', yr, 'ishole', num2cell(false(size(xr))));
end
% Check for dateline crossing
if geo 
    
    p = splitdateline(p(:));
    pc = splitdateline(pc(:));
    pr = splitdateline(pr(:));
    
    
%     for ii = 1:length(pc)
%         pc(ii) = splitdateline(pc(ii))
% %         [pc(ii).y, pc(ii).x] = maptrimp(pc(ii).y, pc(ii).x, [-90 90], [-180 180]);
%     end
%     for ii = 1:length(pr)
%         p = splitdateline(p)
% %         [pr(ii).y, pr(ii).x] = maptrimp(pr(ii).y, pr(ii).x, [-90 90], [-180 180]);
%     end
%     for ii = 1:length(p)
%         p = splitdateline(p)
% %         [p(ii).y, p(ii).x] = maptrimp(p(ii).y, p(ii).x, [-90 90], [-180 180]);
%     end
    
    % Center longitude limits around original polygon, to account for
    % dateline crossings and the like.  
    
%     xlim = minmax(cat(1, p.x));
%     xcent = mean(xlim);
%     xbnd = xcent + [-180 180]; 
%     for ii = 1:length(pc)
%         islo = pc(ii).x < xbnd(1);
%         ishi = pc(ii).x > xbnd(2);
%         pc(ii).x(islo) = pc(ii).x(islo) + 360;
%         pc(ii).x(ishi) = pc(ii).x(ishi) - 360;
%     end
%     
%     for ii = 1:length(pr)
%         islo = pr(ii).x < xbnd(1);
%         ishi = pr(ii).x > xbnd(2);
%         pr(ii).x(islo) = pr(ii).x(islo) + 360;
%         pr(ii).x(ishi) = pr(ii).x(ishi) - 360;
%     end
end
% Plot check
plotflag = false;
if plotflag
    figure;
    hold on;
    arrayfun(@(X) plot(X.x, X.y, 'k'), p);
    arrayfun(@(X) plot(X.x, X.y, 'g'), pc);
    arrayfun(@(X) plot(X.x, X.y, 'b'), pr);
end
% Add or subtract the circles and rectangles from the original polygons
switch direction
    case 'in'
        fun = 'diff';
    case 'out'
        fun = 'union';
end
    
for ic = 1:length(pc)
    p = gpcmex(fun, p, pc(ic));
end
for ir = 1:length(pr)
    p = gpcmex(fun, p, pr(ir));
end
if plotflag
    arrayfun(@(X) plot(X.x, X.y, 'color', 'r', 'linewidth', 2', 'linestyle','--'), p);
end
% Reformat
[x, y] = vectorsFromGPC(p);
if geo
    out1 = y;
    out2 = x;
else
    out1 = x;
    out2 = y;
end
switch outputformat
    case 'vector'
        % Good to go
    case 'cutvector'
        [out1, out2] = polycut(out1, out2);
    case 'cell'
        [out1, out2] = polysplit(out1, out2);
end
%**************************************************************************
function [latc, lonc] = calccircgeo(lat, lon, radius, npts)
% lat and lon: n x 1 vectors
% radius: scalar
radius = ones(length(lat),1) * radius;
[latc, lonc] = scircle1(lat, lon, radius, [], [], [], npts);
latc = num2cell(latc, 1);
lonc = num2cell(lonc, 1);
function [latr, lonr] = calcrecgeo(lat, lon, halfwidth)
% lat and lon: n x 1 vectors
% halfwidth: scalar
range = halfwidth * ones(length(lat)-1, 1);
az = azimuth(lat(1:end-1), lon(1:end-1), lat(2:end), lon(2:end));
[latbl1,lonbl1] = reckon(lat(1:end-1), lon(1:end-1), range, az-90);
[latbr1,lonbr1] = reckon(lat(1:end-1), lon(1:end-1), range, az+90);
[latbl2,lonbl2] = reckon(lat(2:end),   lon(2:end),   range, az-90);
[latbr2,lonbr2] = reckon(lat(2:end),   lon(2:end),   range, az+90);
latr = [latbl1 latbl2 latbr2 latbr1 latbl1]';
lonr = [lonbl1 lonbl2 lonbr2 lonbr1 lonbl1]';
latr = num2cell(latr, 1);
lonr = num2cell(lonr, 1);
        
function [latu, lonu] = multipolyunion(lat, lon)
% lat and lon are n x 1 cell arrays of vectors
latu = lat{1};    
lonu = lon{1};
for ip = 2:length(lat)
    [lonu, latu] = polybool('+', lonu, latu, lon{ip}, lat{ip});
end
[latu, lonu] = polysplit(latu, lonu);
function [xc, yc] = calccirccart(x, y, radius, npts)
ang = linspace(0, 2*pi, npts+1);
ang = ang(end-1:-1:1);
xc = bsxfun(@plus, x, radius * cos(ang));
yc = bsxfun(@plus, y, radius * sin(ang));
xc = num2cell(xc', 1);
yc = num2cell(yc', 1);
% if ~ispolycw(x,y)
%     [xc,yc] = poly2ccw(xc,yc);
% end
function [xrec, yrec] = calcreccart(x, y, halfwidth)
dx = diff(x);
dy = diff(y);
   
is1 = dx >= 0 & dy >= 0;
is2 = dx < 0 & dy >= 0;
is3 = dx < 0 & dy < 0;
is4 = dx >= 0 & dy < 0;
ish1 = dy == 0 & dx > 0;
ish2 = dy == 0 & dx < 0;
theta = zeros(5,1);
theta(is1 | is3) = atan(dy(is1 | is3)./dx(is1 | is3));
theta(is2 | is4) = -atan(dy(is2 | is4)./dx(is2 | is4));
[xl,xr,yl,yr] = deal(zeros(size(dx)));
xl(is1) = -halfwidth * sin(theta(is1));
xr(is1) =  halfwidth * sin(theta(is1));
yl(is1) =  halfwidth * cos(theta(is1));
yr(is1) = -halfwidth * cos(theta(is1));
xl(is2) = -halfwidth * sin(theta(is2));
xr(is2) =  halfwidth * sin(theta(is2));
yl(is2) = -halfwidth * cos(theta(is2));
yr(is2) =  halfwidth * cos(theta(is2));
xl(is3) =  halfwidth * sin(theta(is3));
xr(is3) = -halfwidth * sin(theta(is3));
yl(is3) = -halfwidth * cos(theta(is3));
yr(is3) =  halfwidth * cos(theta(is3));
xl(is4) =  halfwidth * sin(theta(is4));
xr(is4) = -halfwidth * sin(theta(is4));
yl(is4) =  halfwidth * cos(theta(is4));
yr(is4) = -halfwidth * cos(theta(is4));
xrec = [xl+x(1:end-1) xl+x(2:end) xr+x(2:end) xr+x(1:end-1) xl+x(1:end-1)];
yrec = [yl+y(1:end-1) yl+y(2:end) yr+y(2:end) yr+y(1:end-1) yl+y(1:end-1)];
xrec = num2cell(xrec', 1);
yrec = num2cell(yrec', 1);
function p = splitdateline(p)
issplit = false(size(p));
new = [];
for ii = 1:length(p)
    [y, x] = maptrimp(p(ii).y, p(ii).x, [-90 90], [-180 180]);
    if ~isequal(x, p(ii).x)
        issplit(ii) = true;
        [y,x] = polysplit(y,x);
        ishole = num2cell(~ispolycw(x,y));
        if isempty(new)
            new = struct('x', x, 'y', y, 'ishole', ishole);
        else
            new = cat(1, new, struct('x', x, 'y', y, 'ishole', ishole));
        end
    end
end
p = cat(1, p(~issplit), new);
% function [p, pc, pr] = convertlon(p, pc,pr)
% 
% np = length(p);
% nc = length(pc);
% nr = length(pr);
% 
% pall = [p(:); pc(:); pr(:)];
% ndata = length(p);
% 
% lon = cat(1, pall.x);
% 
% iseast = mod(lon, 360) >= 0 & mod(lon,360) <= 180;
% 
% if all(iseast) || ~any(iseast)
%     
%     % If everything is in one hemisphere, can just use min/max
%     
%     lims = minmax(lon);
%     
% else
%     
%     bounds = minmax(lon);
%     crossesdate = all(lon(iswest) <= bounds(1)) & ...
%                   all(lon(iseast) >= bounds(2));
%     crossesprime = all(lon(iswest) >= bounds(1)) & ...
%                    all(lon(iseast) <= bounds(2));
% end
% 
% west = nan(ndata,1);
% east = nan(ndata,1);
%     
% for id = 1:ndata
% 
%     allinhemis = all( >= 0) || all(lon{id}(:) <= 0);
% 
%     bounds = minmax(lon{id});
% 
%     if allinhemis
%         west(id) = bounds(1);
%         east(id) = bounds(2);
%     else
% 
%         iswest = lon{id} <= 0;
%         iseast = lon{id} >= 0;
% 
%         dontknow = isequal(unique(lon{id}), bounds');
%         crossesdate = all(lon{id}(iswest) <= bounds(1)) & ...
%                       all(lon{id}(iseast) >= bounds(2));
%         crossesprime = all(lon{id}(iswest) >= bounds(1)) & ...
%                        all(lon{id}(iseast) <= bounds(2));
% 
% 
%         if dontknow
%             widthoverprime = diff(bounds);
%             widthoverdate = (bounds(1)+180) + (180-bounds(2));
%             if widthoverprime < widthoverdate
%                 west(id) = bounds(1);
%                 east(id) = bounds(2);
%             else
%                 west(id) = bounds(2);
%                 east(id) = bounds(1);
%             end
%         elseif crossesprime
%             west(id) = min(lon{id}(iseast));
%             east(id) = max(lon{id}(iswest));
% %                 west(id) = bounds(1);
% %                 east(id) = bounds(2);
%         elseif crossesdate
%             west(id) = bounds(2);
%             east(id) = bounds(1);
%         end    
% 
%     end
% 
% end
% 
% % Figure out west-east bounds of plot that minimize lon span while
% % including all objects
% 
% 
% for id = 1:ndata
%     westbound(id) = west(id);
%     eastbounds{id} = [east; west];
%     isless = eastbounds{id} < westbound(id);
%     eastbounds{id}(isless) = eastbounds{id}(isless) + 360;
%     lonspan(id) = max(eastbounds{id}) - westbound(id);
% end
% 
% [minval, imin] = min(lonspan);
% 
% % Convert bounds to either -180-180 or 0-360 coords as appropriate
% 
% westmap = mod(westbound(imin) - In.buffer, 360);
% eastmap = mod(max(eastbounds{imin}) + In.buffer, 360);
% 
% if westmap > eastmap
%     westmap = westmap - 360;
% end
% 
% 
%     
    