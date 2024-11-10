clear all
close all
clc
%%

RGB = imread('input.png');
image1=RGB;
figure();
imshow(RGB);
title('Original Image');

%%
image2 = image1;
for i=1:1050
    for j=1:1208
        if (image1(i,j,1)<140) || (image1(i,j,2)<140) || (image1(i,j,3)<140)
            image2(i,j,:)=255;
        else
            image2(i,j,:)=0;
        end
    end
end
figure();
imshow(image2);
title('Black and White');
%%
image2 = im2bw(image2);
STATS = regionprops(image2, 'all');



















%% Lab 2 Code
%[B,L] = bwboundaries(image2, 'noholes');
%STATS = regionprops(L, 'all');


figure();
imshow(RGB);
title('Results');








%%%%%
hold on
for i = 1 : length(STATS)
    W(i) = uint8(abs(STATS(i).BoundingBox(3)-STATS(i).BoundingBox(4)) > 1);
    W(i) = W(i) + 2 * uint8((STATS(i).Extent - 1) == 0 );
    diameters = mean([STATS(i).MajorAxisLength STATS(i).MinorAxisLength],2);
    radii = diameters/2;
    
    centroid = STATS(i).Centroid;
    if STATS(i).Area > 200 && STATS(i).Area < 100000
        radii;
        if radii > 42 && radii < 50
            plot(centroid(1),centroid(2),'wO');
            round(centroid(1));
            round(centroid(2));
            RGB(round(centroid(2)),round(centroid(1)),1);
            RGB(round(centroid(2)),round(centroid(1)),2);
            RGB(round(centroid(2)),round(centroid(1)),3);
            if (RGB(round(centroid(2)),round(centroid(1)),1) > RGB(round(centroid(2)),round(centroid(1)),2)) && (RGB(round(centroid(2)),round(centroid(1)),1) > RGB(round(centroid(2)),round(centroid(1)),3)) && RGB(round(centroid(2)),round(centroid(1)),2) < 150
                text(centroid(1)+50,centroid(2)+50,'RED');
            end
            if (RGB(round(centroid(2)),round(centroid(1)),2) > RGB(round(centroid(2)),round(centroid(1)),1)) && (RGB(round(centroid(2)),round(centroid(1)),2) > RGB(round(centroid(2)),round(centroid(1)),3)) && RGB(round(centroid(2)),round(centroid(1)),2) < 150
                text(centroid(1)+50,centroid(2)+50,'GREEN');
            end
            if (RGB(round(centroid(2)),round(centroid(1)),3) > RGB(round(centroid(2)),round(centroid(1)),2)) && (RGB(round(centroid(2)),round(centroid(1)),3) > RGB(round(centroid(2)),round(centroid(1)),1))
                text(centroid(1)+50,centroid(2)+50,'BLUE');
            end
            if RGB(round(centroid(2)),round(centroid(1)),1) > 150 && RGB(round(centroid(2)),round(centroid(1)),2) > 150
                text(centroid(1)+50,centroid(2)+50,'YELLOW');
            end
            
        end
        if radii > 33.5 && radii < 42
            plot(centroid(1),centroid(2),'wS');
            round(centroid(1));
            round(centroid(2));
            RGB(round(centroid(2)),round(centroid(1)),1);
            RGB(round(centroid(2)),round(centroid(1)),2);
            RGB(round(centroid(2)),round(centroid(1)),3);
            if (RGB(round(centroid(2)),round(centroid(1)),1) > RGB(round(centroid(2)),round(centroid(1)),2)) && (RGB(round(centroid(2)),round(centroid(1)),1) > RGB(round(centroid(2)),round(centroid(1)),3)) && RGB(round(centroid(2)),round(centroid(1)),2) < 150
                text(centroid(1)+50,centroid(2)+50,'RED');
            end
            if (RGB(round(centroid(2)),round(centroid(1)),2) > RGB(round(centroid(2)),round(centroid(1)),1)) && (RGB(round(centroid(2)),round(centroid(1)),2) > RGB(round(centroid(2)),round(centroid(1)),3)) && RGB(round(centroid(2)),round(centroid(1)),2) < 150
                text(centroid(1)+50,centroid(2)+50,'GREEN');
            end
            if (RGB(round(centroid(2)),round(centroid(1)),3) > RGB(round(centroid(2)),round(centroid(1)),2)) && (RGB(round(centroid(2)),round(centroid(1)),3) > RGB(round(centroid(2)),round(centroid(1)),1))
                text(centroid(1)+50,centroid(2)+50,'BLUE');
            end
            if RGB(round(centroid(2)),round(centroid(1)),1) > 150 && RGB(round(centroid(2)),round(centroid(1)),2) > 150
                text(centroid(1)+50,centroid(2)+50,'YELLOW');
            end
        end
        if radii < 33.5
            plot(centroid(1),centroid(2),'wX');
            round(centroid(1));
            round(centroid(2));
            RGB(round(centroid(2)),round(centroid(1)),1);
            RGB(round(centroid(2)),round(centroid(1)),2);
            RGB(round(centroid(2)),round(centroid(1)),3);
            if (RGB(round(centroid(2)),round(centroid(1)),1) > RGB(round(centroid(2)),round(centroid(1)),2)) && (RGB(round(centroid(2)),round(centroid(1)),1) > RGB(round(centroid(2)),round(centroid(1)),3)) && RGB(round(centroid(2)),round(centroid(1)),2) < 150
                text(centroid(1)+50,centroid(2)+50,'RED');
            end
            if (RGB(round(centroid(2)),round(centroid(1)),2) > RGB(round(centroid(2)),round(centroid(1)),1)) && (RGB(round(centroid(2)),round(centroid(1)),2) > RGB(round(centroid(2)),round(centroid(1)),3)) && RGB(round(centroid(2)),round(centroid(1)),2) < 150
                text(centroid(1)+50,centroid(2)+50,'GREEN');
            end
            if (RGB(round(centroid(2)),round(centroid(1)),3) > RGB(round(centroid(2)),round(centroid(1)),2)) && (RGB(round(centroid(2)),round(centroid(1)),3) > RGB(round(centroid(2)),round(centroid(1)),1))
                text(centroid(1)+50,centroid(2)+50,'BLUE');
            end
            if RGB(round(centroid(2)),round(centroid(1)),1) > 150 && RGB(round(centroid(2)),round(centroid(1)),2) > 150
                text(centroid(1)+50,centroid(2)+50,'YELLOW');
            end
        end
       
    end
end