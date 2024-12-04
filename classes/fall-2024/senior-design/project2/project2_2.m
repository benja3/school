clear all;
close all;
clear camObject;
clc;

% create constants with tolerances for RGhukhB values


spaceWidth = 60; %pixels
spaceHeight = 60; %pixels
startingCoord = [90 45];
circle_centroid_x = 320;
circle_centroid_y = 240;

% find pixel coordinates of different spaces on board
gameBoard = [];

for row = 1 : 8
    for col = 1 : 8
        gameBoard(row, col, 1) = startingCoord(1) + spaceHeight * (row - 1);
        gameBoard(row, col, 2) = startingCoord(2) + spaceWidth * (col - 1);
    end
end


gameState = struct; % data structure for game state information
gameState.boardCoords = gameBoard;
gameState.objects = [];

% user input

user_shape = input("What shape are you looking for? (circle, square, triangle)\n", "s");
user_color = input("What is the color of the shape? (red, yellow, green, blue)\n", "s");

% set up camera

cam_list = webcamlist;

imaqhwinfo

imaqmex('feature', '-limitPhysicalMemoryUsage', false)

vid = videoinput("linuxvideo", 1, "RGB24_640x480");

set(vid, 'TriggerRepeat', Inf)

vid.FrameGrabInterval = 300;

start(vid)

count = 0;

% take base image

data = getdata(vid,1);
base = data(:,:,:,1);

figure(); 
imshow(base);

% collect and process frames until counter limit reached

while (count < 1)
    
    % capture current frame 
    data = getdata(vid,1);
    img = data(:,:,:,1);

    figure();
    imshow(img);

    [height, width, depth] = size(img);
    
    % perform background subtraction to highlight changes

    back_sub = base - img;

    back_sub = im2bw(back_sub, 0.05);

    SE = strel('disk',5);
    back_sub = imdilate(back_sub, SE);
    
    figure();
    imshow(back_sub);
    imwrite(base, 'board_mat.jpg');
    
    % analyze regions for potential shapes 

    raw_regions = regionprops(back_sub, 'all');
       
    % collect info for each region
    for i = 1 : length(raw_regions)
        
        % detect whether color or gray
        centroid_1 = round(raw_regions(i).Centroid(1)); % x
        centroid_2 = round(raw_regions(i).Centroid(2)); % y
        
        % rgb values at centroid coords
        centroid_r = img(centroid_2, centroid_1, 1);
        centroid_g = img(centroid_2, centroid_1, 2);
        centroid_b = img(centroid_2, centroid_1, 3);
        
        centroid_rgb = [centroid_r centroid_g centroid_b];
   
        % do not process extremely small or large regions likely created by noise 
        if raw_regions(i).Area > 1000 && raw_regions(i).Area < 5000
         
            Area = raw_regions(i).Area;
            % color detection

            centroid_r = cast(centroid_r, 'int32');
            centroid_g = cast(centroid_g, 'int32');
            centroid_b = cast(centroid_b, 'int32');
            
            color_diff = abs(centroid_r - centroid_g)
        
            if(color_diff < 20) % if red and green values are close
                Color = "yellow";
            elseif (centroid_r > centroid_g && centroid_r > centroid_b)
                Color = "red";
            elseif (centroid_g > centroid_r && centroid_g > centroid_b)
                Color = "green";
            elseif (centroid_b > centroid_r && centroid_b > centroid_g)
                Color = "blue";
            else
                Color = "null";
            end


            % Shape

            if raw_regions(i).Circularity > 0.91
                Shape = "circle";
            elseif Area > 2000
                Shape = "square";
            else 
                Shape = "triangle";
            end

            % Location

            Location = [centroid_1 centroid_2];
            gameObject = [ Area, Color, Shape, Location];
            
            % when done, store object in gameState
            gameState.objects = [gameState.objects; gameObject];


        end


    end

    % project 3 
    
    [rows, cols] = size(gameState.objects);
    for i = 1 : rows
        if ( gameState.objects(i,2) == user_color && gameState.objects(i,3) == user_shape )
            angular_x = cast(str2num(gameState.objects(i,4)) - cast(circle_centroid_x, 'int32'), 'double');
            angular_y = cast(str2num(gameState.objects(i,5)) - cast(circle_centroid_y, 'int32'), 'double');

            result_arctan = atan2d(angular_y, angular_x);
            
            if result_arctan < 0
                final_degree = abs(result_arctan);
            elseif result_arctan > 0
                final_degree = 360 - result_arctan;
            else
                final_degree = 0;
            end

            % send angle_degree to motor

            set_param('/home/benja/Downloads/MotorModel_Sp23_V22b.slx', 'desiredPosition', final_degree);

        end

    end
   
    count = count  + 1;
    

end

stop(vid)

