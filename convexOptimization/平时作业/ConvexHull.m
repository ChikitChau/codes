% 从100个随机点计算所有有可能的凸包
hold on
N=100;
Points = rand(N,2);

SortedX = sortrows(Points,1);
NewVertices = SortedX;

plot(SortedX(:,1),SortedX(:,2),'*');

while length(NewVertices)>=3
    X=NewVertices(:,1);
    Y=NewVertices(:,2);
    K = convhull(X,Y);
    plot(X(K),Y(K),'r-');
    for i=1:length(K)-1
        NewVertices(K(i),1)=0;
        NewVertices(K(i),2)=0;
    end
    NewVertices = NewVertices(any(NewVertices,2),:);
end