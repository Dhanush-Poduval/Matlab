function [x,y]=ik_function(b , endEffector , weights , points,q0 , size)
    ik=inverseKinematics('RigidBodyTree',b);
    for i=1:size
        point=points(i,:);
        [a0,~]=ik(endEffector,trvec2tform(point),weights,q0);
        x(i,:)=a0;
        q0=a0;
        y(i,:)=[a0.JointPosition];
    end

