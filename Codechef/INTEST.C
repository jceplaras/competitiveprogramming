int main() {
	int n, k, c = 0;
	int a;
	scanf("%d %d",&n,&k);
	
	for(;n>=0;n--) {
		scanf("%d",&a);
		c+=(a%k)?0:1;
	}
	printf("%d",c);
return 0;
}