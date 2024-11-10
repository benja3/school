clear all;
close all;
clear camObject;
clc;

% create constants with tolerances for RGB values

spaceWidth = 60; %pixels
spaceHeight = 60; %pixels
startingCoord = [90 45];

% find pixel coordinates of different spaces on board
gameBoard = []

for row = 1 : 8
    for col = 1 : 8
        gameBoard(row, col, 1) = startingCoord(1) + spaceHeight * (row - 1);
        gameBoard(row, col, 2) = startingCoord(2) + spaceWidth * (col - 1);
    end
end


gameState = struct; % data structure for game state information
gameState.boardCoords = gameBoard;
% gameState.key = {}

cam_list = webcamlist 

imaqhwinfo

imaqmex('feature', '-limitPhysicalMemoryUsage', false)

vid = videoinput("linuxvideo", 1, 'RGB24_640x480')

set(vid, 'TriggerRepeat', Inf)

vid.FrameGrabInterval = 90;

start(vid)

count = 0;

% take base image
data = getdata(vid,1);
base = data(:,:,:,1);

figure();
imshow(base);

while (count < 1)
    
    data = getdata(vid,1);
    img = data(:,:,:,1);
    
    back_sub = base - img;
    
    figure();
    imshow(back_sub);
    imwrite(base, 'board_mat.jpg');
    
    raw_regions = regionprops(back_sub, 'all')
    
    processed_regions = [];
   
    for i = 1 : length(raw_regions)
       
         % detect whether color or gray
         centroid_1 = round(raw_regions(i).Centroid(1));
         centroid_2 = round(raw_regions(i).Centroid(2));
         centroid_r = back_sub(centroid_1, centroid_2, 1);
         centroid_g = back_sub(centroid_1, centroid_2, 2);
         centroid_b = back_sub(centroid_1, centroid_2, 3);
 
         centroid_rgb = [centroid_r centroid_g centroid_b]

        if raw_regions(i).Area > 200 && raw_regions(i).Area < 600
            processed_regions = [ processed_regions raw_regions(i)];
        end


    end
   
    count = count  + 1;
    

end

stop(vid)

% use text funciton for image annoation





