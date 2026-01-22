N=100;
f(1)=1;
f(2)=1;
fibonnaci_array=[1,2,3,4,5,6,7,8,9,10];
for n =3:N
    f(n)=f(n-1)+f(n-2);
end
plot(fibonnaci_array,f(1:10));
xlabel('values');
ylabel('Fibbonaci numbers');
title("Fibonnaci Sequence");
num=randi(100);
if num>60
    sz="Low";
elseif num <10
    sz="Very low";
else
    sz="Mid";
end
disp(sz);

 