v=0:0.00614:2*pi;
x = sin(v) + 0.3*rand(1,numel(v));
y=averaginffiltermlCG(theta);
plot(x,'Color','r');
hold on ;
plot(y,'Color','b','LineStyle','--');
hold off;