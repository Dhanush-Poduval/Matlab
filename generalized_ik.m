robot=loadrobot("kukaIiwa14","DataFormat","row");
showdetails(robot);
grid on;
endEffector="iiwa_link_ee_kuka";
cup_Height=0.2;
cup_Radius=0.05;
cup_position=[-0.5,0.6,cup_Height/2];
[x,y,z]=cylinder(cup_Radius);
x=x-0.5;
y=y+0.6;
z=z*cup_Height;
hold on;
surf(x,y,z);
show(robot);
axis equal;
hold off