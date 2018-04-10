#include <cstdio>
#include <vector>
#include <algorithm>
int main(){
	std::vector<int> pos;
	int length,num,left,change = 0,min = 1;
	scanf("%d",&length);
	pos.resize(length);
	left = length -1;
	for (int i = 0; i < length; ++i)
	{
		scanf(" %d",&num);
		pos[num] = i;
		if (num == i && num != 0)
		{ 
			--left;
		}
	}
	while(left>0){
		if (pos[0] == 0)
		{
			while(min < pos.size()){
				if(pos[min] != min){
					std::swap(pos[0],pos[min]);
					++change;
					break;
				}
				++min;
			}
		}
		while(pos[0] != 0){
			std::swap(pos[0],pos[pos[0]]);
			++change;
			--left;
		}
	}
	printf("%d\n",change );
	return 0;
}