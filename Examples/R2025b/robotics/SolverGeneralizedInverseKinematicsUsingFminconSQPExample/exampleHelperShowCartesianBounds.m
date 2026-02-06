function exampleHelperShowCartesianBounds(bounds,faceAlpha)

    % Extract bounds
    xBounds = bounds(1,:);
    yBounds = bounds(2,:);
    zBounds = bounds(3,:);

    % Define vertices of the box
    vertices = [xBounds(1) yBounds(1) zBounds(1);
                xBounds(1) yBounds(1) zBounds(2);
                xBounds(1) yBounds(2) zBounds(1);
                xBounds(1) yBounds(2) zBounds(2);
                xBounds(2) yBounds(1) zBounds(1);
                xBounds(2) yBounds(1) zBounds(2);
                xBounds(2) yBounds(2) zBounds(1);
                xBounds(2) yBounds(2) zBounds(2)];

    % Define faces of the box
    faces = [1 2 4 3; % -X face
             5 6 8 7; % +X face
             1 2 6 5; % -Y face
             3 4 8 7; % +Y face
             1 3 7 5; % -Z face
             2 4 8 6]; % +Z face

    % Plot the box
    c = colororder;
    patch(Vertices=vertices,Faces=faces,FaceAlpha=faceAlpha,FaceColor=c(1,:));
end