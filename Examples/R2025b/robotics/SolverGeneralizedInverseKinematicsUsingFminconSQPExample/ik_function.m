function [x,y]=ik_function(endEffector , weights , points,q0 , scalar_size)%#codegen

arguments
    endEffector (1,:) char
    weights (1,:) double
    points (1,:) double
    q0 (1,2) double
    scalar_size (1,1) int16
end

    b=robotBuildforCodegen();
    ik=inverseKinematics('RigidBodyTree',b);
    x=zeros(scalar_size,2);
    y=zeros(scalar_size,2);
    for i=1:scalar_size
        point=points(i,:);
        [a0,~]=ik(endEffector,trvec2tform(point),weights,q0);
        x(i,:)=a0;
        q0=a0;
        y(i,:)=a0;
    end

