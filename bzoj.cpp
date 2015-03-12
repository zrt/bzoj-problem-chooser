#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<ctime>
using namespace std;
void read_data(){
	freopen("data.dat","r",stdin);
}
void read_done(){
	freopen("done.txt","r",stdin);
}
void read_black(){
	freopen("black.txt","r",stdin);
}
void write_data(){
	freopen("data.dat","w",stdout);
}
void write_done(){
	freopen("done.txt","w",stdout);
}
void write_black(){
	freopen("black.txt","w",stdout);
}

void close_in(){
	fclose(stdin);
}
void close_out(){
	fclose(stdout);
}

struct Data{
	int id,ac,num;
	double rate;
	int done;
	void calc(){
		if(num==0) rate=0;
		else rate=(ac/(double) num)/2+ac/10000.0;
	}
	void read(int t){
		id=t;
		scanf("%d%d",&ac,&num);
		calc();
	}
}problem_set[5005];
int n;
map<int,int> mp;
double hard;
void read(){
	#ifdef WIN32
	 freopen("CON","r",stdin);
	#else
	 freopen("/dev/tty","r",stdin);
	#endif
}
double ret;
char s[100];
int get(){
	int id=rand()%n+1;
	if(problem_set[id].done) return -1;
	if(problem_set[id].rate>hard){
		ret=1+problem_set[id].rate-hard;
		return id;
	}else if(hard-problem_set[id].rate<0.4&&problem_set[id].ac>300){
		ret=1+problem_set[id].rate-hard;
		return id;
	}else if(hard-problem_set[id].rate<0.2){
		ret=1+problem_set[id].rate-hard;
		return id;
	}else if(rand()<100){
		ret=1+problem_set[id].rate-hard;
		return id;
	}else return -1;
}
int t;
void read_(){
	read_data();
	srand(time(0));
	int t;
	while(~scanf("%d",&t)){
		n++;
		problem_set[n].read(t);
		mp[t]=n;
	}
	close_in();
	read_done();
	while(~scanf("%d",&t)){
		problem_set[mp[t]].done=1;
	}
	close_in();
	read_black();
	while(~scanf("%d",&t)){
		problem_set[mp[t]].done=2;
	}
	close_in();
}

int main(){
	
	http://www.lydsy.com/JudgeOnline
	
	read_();
	read();
	
	puts("==========================");
	puts("|  BZOJ problem chooser  |");
	puts("|      version: 1e-8     |");
	puts("|        ORZ GMH         |");
	puts("==========================");
	
	puts("Input a float number between (0,1). (less is harder)");
	scanf("%lf",&hard);
	
	puts("If you like new-problem input 1,old-problem input 2 ,both input 3:");
	scanf("%d",&t);
	
	if(t==1){
		int mid=n/2;
		for(int i=1;i<=n;i++){
			problem_set[i].rate=problem_set[i].rate*(1-(i-mid)/(double)n*0.1);
		}
	}else if(t==2){
		int mid=n/2;
		for(int i=1;i<=n;i++){
			problem_set[i].rate=problem_set[i].rate*(1-(i-mid)/(double)n*0.1);
		}
	}
	srand((unsigned)(rand()*hard));
	
	puts("Ready?");
	for(int i=0;i<=150000000;i++);
	puts("3");
	for(int i=0;i<=150000000;i++);
	puts("2");
	for(int i=0;i<=150000000;i++);
	puts("1");
	
	int id;
	while(1){
		#ifdef WIN32
		system("cls");
		#endif
		int num=0;
		while((id=get())==-1&&num<=1000) num++;
		if(num>1000){
			puts("ORZ ORZ ORZ ORZ ORZ ORZ ");
			break;
		}
		puts("\n");
		printf("I choose problem %d for you\nand the difficulty for you is %.3f.(less is harder.)\n",problem_set[id].id,ret);
		puts("");
		puts("If you AC print 'y' \nelse if print 'n' to add this problem to the blacklist\nelse print 'c' to continue.");
		scanf("%s",s);
		if(s[0]=='y'){
			problem_set[id].done=1;
		}else if(s[0]=='n'){
			problem_set[id].done=2;
		}
		puts("Press 'q' to quit ,press 'c' to continue.");
		scanf("%s",s);
		if(s[0]=='q'){
			break;
		}
	}
	#ifdef WIN32
	system("cls");
	#endif
	if(rand()&1) puts("Bye bye!");
	else puts("Farewell.");
	write_done();
	for(int i=1;i<=n;i++) if(problem_set[i].done==1){
		printf("%04d\n",problem_set[i].id);
	}
	write_black();
	for(int i=1;i<=n;i++) if(problem_set[i].done==2){
		printf("%04d\n",problem_set[i].id);
	}
	close_out();
	return 0;
}
