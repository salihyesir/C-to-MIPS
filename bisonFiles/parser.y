%{
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include<stdio.h> 
#include<string.h> 

#include <map>
#include <string>
#include<fstream>
using namespace std;
extern int yylex(void);
extern int yylineno;
extern char* yytext;
void yyerror(char const*);	

struct Node
{
	int reg;
	int type;
	int value;
};
using namespace std;

ofstream sonuc; 
//.data alanını yazmak için
void data();
//hafıdan ilk boş olan yeri almak için
int hafizadan_al();
void hafizadan_sil(int);
void hafizayi_bosalt();
void arttir_azalt(char*,int,int,bool,char);

//tahsis işlemleri(int dizi char )içerisinde tip değişken kontrolü la li vs işlemler
void atama(string,int,int,int,int,int);
//temp
Node h_yukle(char*,int,int,int);

//add sub mult div seq sle slt sge sgt or and seq mtc1 cvt
//string işlem tipini belirler
Node islemler(int,int,string,int,int);


char temp[20]; //cout için kullanıldı. art azlt

int hafiza[1000];
//node f ve atama içeirisinde type a göre li ikinci kısımda kullan
//dizi için 4 int 1 char 
int size[3]={4,1};
map <string,int> type_map;
map <string,int> size_map;


%}
%union {
	struct Node
	{
		int reg;
		int type;
	}node;
	int type_val;
	char str[500];//sayı id char,,
}

%token TOPLA CIKAR CARP BOL MOD ESIT ARTTIR AZALT ESIT_MI ESITDEGIL_MI GT LT GTE LTE 
VEYA VE DEGIL B_OR B_AND B_XOR SOLPARANTEZ SAGPARANTEZ KOSELISOLPAR KOSELISAGPAR SOLSUSLUPAR SAGSUSLUPAR 
VIRGUL NOKTALIVIRGUL NOKTA IKINOKTA ELSE ERROR STRING_CONSTANT TIRNAK
%token <str> SAYI ID KARAKTER
%token <type_val> DATATYPE MAIN FOR WHILE IF EIF COUT
%type <node> s stm_list stm simple_stm r_ifade sr_ifade ifade term factor artrazlt p_artrazlt temp_id
%start s

%%
s : stm_list

stm_list : stm stm_list {}
	| %empty {}
	
stm : simple_stm NOKTALIVIRGUL
	| MAIN SOLPARANTEZ SAGPARANTEZ SOLSUSLUPAR stm_list SAGSUSLUPAR {/*cout<<"\tjr  $ra"<<endl; sonuc<<"\tjr  $ra"<<endl;*/}
	| SOLSUSLUPAR stm_list SAGSUSLUPAR {}
	| IF SOLPARANTEZ r_ifade SAGPARANTEZ {
			cout<<"\tbeq $t"<<$3.reg<<",$zero,end_"<<$1<<endl;hafizadan_sil($3.reg);
	  	sonuc<<"\tbeq $t"<<$3.reg<<",$zero,end_"<<$1<<endl;hafizadan_sil($3.reg);} stm {
				cout<<"\tj end_"<<$1<<endl;sonuc<<"\tj end_"<<$1<<endl;
		 		cout<<"end_"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
		 		sonuc<<"end_"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;}
	| WHILE {
			cout<<"while_loop_"<<$1<<":"<<endl<<"\tadd $t0,$t0,$zero"<<endl;
			sonuc<<"while_loop_"<<$1<<":"<<endl<<"\tadd $t0,$t0,$zero"<<endl;
			} 
			SOLPARANTEZ r_ifade {
				cout<<"\tbeq $t"<<$4.reg<<",$zero,e"<<$1<<endl; sonuc<<"\tbeq $t"<<$4.reg<<",$zero,e"<<$1<<endl; 
				hafizadan_sil($4.reg);} SAGPARANTEZ stm {
					cout<<"\tj while_loop_"<<$1<<"\n"<<"e"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
		 			sonuc<<"\tj while_loop_"<<$1<<"\n"<<"e"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;} 
	| FOR SOLPARANTEZ simple_stm {
		cout<<"for_loop_"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
	  sonuc<<"for_loop_"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;} NOKTALIVIRGUL r_ifade  {
			cout<<"\tbeq $t"<<$6.reg<<",$zero,e"<<$1<<endl;hafizadan_sil($6.reg);
		 	sonuc<<"\tbeq $t"<<$6.reg<<",$zero,e"<<$1<<endl;hafizadan_sil($6.reg);} NOKTALIVIRGUL {
				 	cout<<"\tj f"<<$1<<"\n"<<"ef"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
					sonuc<<"\tj f"<<$1<<"\n"<<"ef"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;} simple_stm {
						cout<<"\tj for_loop_"<<$1<<endl; sonuc<<"\tj for_loop_"<<$1<<endl;} 
	  				SAGPARANTEZ {
								cout<<"\tf"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;
								sonuc<<"\tf"<<$1<<":\n"<<"\tadd $t0,$t0,$zero"<<endl;} stm {
									cout<<"\tj ef"<<$1<<"\n"<<"e"<<$1<<":\n\tadd $t0,$t0,$zero"<<endl;
									sonuc<<"\tj ef"<<$1<<"\n"<<"e"<<$1<<":\n\tadd $t0,$t0,$zero"<<endl;}
	| EIF SOLPARANTEZ r_ifade {
		cout<<"beq $t"<< $3.reg <<",$zero,else_"<<$1<<endl;
		sonuc<<"beq $t"<< $3.reg <<",$zero,else_"<<$1<<endl;hafizadan_sil($3.reg);} SAGPARANTEZ stm {
		cout<<"j end_"<<$1<<endl;sonuc<<"j end_"<<$1<<endl;
		cout<<"else_"<<$1<<":\n\tadd $t0,$t0,$zero"<<endl;sonuc<<"else_"<<$1<<":\n\tadd $t0,$t0,$zero"<<endl;} 
	ELSE stm {
		cout<<"j end_"<<$1<<endl;sonuc<<"j end_"<<$1<<endl;
		cout<<"end_"<<$1<<":\nadd $t0,$t0,$zero"<<endl;sonuc<<"end_"<<$1<<":\nadd $t0,$t0,$zero"<<endl;}
	| COUT LT LT ID NOKTALIVIRGUL {
			if(type_map.find(string($4))!=type_map.end()){	
				if(type_map[string($4)] == 0){ cout<<"\tli $v0, 1"<<endl;sonuc<<"\tli $v0, 1"<<endl; 
					cout<<"\tlw $a0"<<","<<$4<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tlw $a0"<<","<<$4<<endl<<"\tsyscall"<<endl;}	 
			if(type_map[string($4)] == 1){
				cout<<"\tli $v0, 4"<<endl;sonuc<<"\tli $v0, 4"<<endl; 
				cout<<"\tla $a0"<<","<<$4<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tla $a0"<<","<<$4<<endl<<"\tsyscall"<<endl;
			}
		}else yyerror("Degisken tipi bildirilmemis");}
	|	COUT LT LT p_artrazlt NOKTALIVIRGUL{}// arttir_azalt fonksiyonu içerisinde halledildi
	| COUT LT LT ID KOSELISOLPAR r_ifade KOSELISAGPAR  NOKTALIVIRGUL{
			if(type_map.find(string($4))!=type_map.end()){	
				if(type_map[string($4)] == 0){ cout<<"\tli $v0, 1"<<endl;sonuc<<"\tli $v0, 1"<<endl;
					int temp = hafizadan_al();
					cout<<"\tla $t"<<temp<<","<<$4<<"_degiskeni"<<endl;sonuc<<"\tla $t"<<temp<<","<<$4<<"_degiskeni"<<endl;
					cout<<"\tmul $t"<<$6.reg<<",$t"<<$6.reg<<","<<4<<endl;sonuc<<"\tmul $t"<<$6.reg<<","<<4<<endl;
					cout<<"\tadd $t"<<temp<<",$t"<<temp<<",$t"<<$6.reg<<endl;sonuc<<"\tadd $t"<<temp<<",$t"<<temp<<",$t"<<$6.reg<<endl;
					cout<<"\tlw $a0"<<","<<"($t"<<temp<<")"<<endl<<"\tsyscall"<<endl;sonuc<<"\tlw $a0"<<","<<"($t"<<temp<<")"<<endl<<"\tsyscall"<<endl;
					hafizadan_sil(temp);}
			if(type_map[string($4)] == 1){
					cout<<"\t#Butun karakter dizi basilacaktir. Bu sekilde tasarladim."<<endl;
					cout<<"\tli $v0, 4"<<endl;sonuc<<"\tli $v0, 4"<<endl; 
					int temp = hafizadan_al();
					cout<<"\tla $a0,"<<$4<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tla $t"<<temp<<","<<$4<<"_degiskeni"<<endl;
					hafizadan_sil(temp);}
			}
		else yyerror("Degisken tipi bildirilmemis");}
	

 


/*
	type_map.find(string($2))==type_map.end() =>>> aynı tipte bir değişken bulanamazsa true döner type_map[string($2)]=$1 bununlada değişkeni
	tipini verirsin 
*/
	//DATATYPE ID ESIT r_ifade; DATATYPE $1 bunun type valuesu var , ID $2 bunun strsi var , ESIT $3 bu düz token hiçbirşeyi yok , 
	//r_ifade  $4 ü sembolize eder bunu node olarak tasarladım regi type herşeyi var.
simple_stm : ID ESIT r_ifade {
		atama(string($1),$3.type,$3.reg,0,0,0);hafizayi_bosalt();}
	| ID KOSELISOLPAR r_ifade KOSELISAGPAR ESIT r_ifade {
			atama(string($1),$6.type,$6.reg,$3.type,$3.reg,1);hafizayi_bosalt();}
	| DATATYPE ID {
		if(type_map.find(string($2))==type_map.end()){type_map[string($2)]=$1;}
	  else yyerror("Degisken tipi bildirilmemis");hafizayi_bosalt();}
	| DATATYPE ID ESIT r_ifade {
		if(type_map.find(string($2))==type_map.end()){
			type_map[string($2)]=$1;
	  	atama(string($2),$4.type,$4.reg,0,0,0);}
			else{
					yyerror("Degisken tipi bildirilmemis");};hafizayi_bosalt();}
	| DATATYPE ID KOSELISOLPAR SAYI KOSELISAGPAR {
		if(type_map.find(string($2))==type_map.end()){
				size_map[string($2)]=atoi($4);type_map[string($2)]=$1;
				}else {yyerror("Degisken tipi bildirilmemis");};hafizayi_bosalt();}
	| artrazlt {hafizayi_bosalt();}
	| %empty {}

r_ifade  : r_ifade VEYA sr_ifade {
		Node n = islemler($1.reg,$3.reg,"||",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;} 
	| r_ifade VE sr_ifade {
		Node n = islemler($1.reg,$3.reg,"&&",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| sr_ifade {$$=$1;} 


//şart ifadeleri
sr_ifade : sr_ifade ESIT_MI ifade {
			Node n = islemler($1.reg,$3.reg,"==",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| sr_ifade ESITDEGIL_MI ifade {
		Node n = islemler($1.reg,$3.reg,"!=",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| sr_ifade LT ifade {
		Node n = islemler($1.reg,$3.reg,"<",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| sr_ifade GT ifade {
		Node n = islemler($1.reg,$3.reg,">",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| sr_ifade LTE ifade {
		Node n = islemler($1.reg,$3.reg,"<=",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| sr_ifade GTE ifade  {
		Node n = islemler($1.reg,$3.reg,">=",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| ifade {$$ = $1;}

ifade : ifade TOPLA term {
		Node n = islemler($1.reg,$3.reg,"+",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| ifade CIKAR term {
		Node n = islemler($1.reg,$3.reg,"-",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| ifade B_AND term{
		Node n = islemler($1.reg,$3.reg,"&",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| ifade B_OR term{
		Node n = islemler($1.reg,$3.reg,"|",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| ifade B_XOR term{
		Node n = islemler($1.reg,$3.reg,"^",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| DEGIL term{ 
		Node n = islemler($2.reg,$2.reg,"!",$2.type,$2.type);$$.reg = n.reg;$$.type = n.type;}
	| term {$$ = $1;}
//sıralama olarak mod carpma vs önde olduğu için ikiye ayrıldı.
term : term CARP factor {
		Node n = islemler($1.reg,$3.reg,"*",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| term BOL factor { 
		Node n = islemler($1.reg,$3.reg,"/",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| term MOD factor {
		Node n = islemler($1.reg,$3.reg,"%",$1.type,$3.type);$$.reg = n.reg;$$.type = n.type;}
	| factor {$$ = $1;}

//atoi ile inte dönüştürüyoruz.
factor : SAYI {$$.reg=hafizadan_al();cout<<"\tli $t"<<$$.reg<<","<<$1<<endl;sonuc<<"\tli $t"<<$$.reg<<","<<$1<<endl;$$.type=0;}
	| SOLPARANTEZ r_ifade SAGPARANTEZ {$$=$2;}
	| temp_id {$$=$1;}
	| CIKAR SAYI {$$.reg=hafizadan_al();cout<<"\tli $t"<<$$.reg<<","<<$2<<endl;
		sonuc<<"\tli $t"<<$$.reg<<","<<($2)<<endl;$$.type=0;}
	| CIKAR temp_id {cout<<"neg $t"<<$2.reg<<","<<"$t"<<$2.reg<<endl;
		sonuc<<"neg $t"<<$2.reg<<","<<"$t"<<$2.reg<<endl;$$=$2;}
	| artrazlt {$$=$1;}
	| AZALT SAYI {$$.reg=hafizadan_al();cout<<"\tli $t"<<$$.reg<<","<<atoi($2)-1<<endl;
		sonuc<<"\tli $t"<<$$.reg<<","<<atoi($2)-1<<endl;$$.type=0;}
	| ARTTIR SAYI {$$.reg=hafizadan_al();cout<<"\tli $t"<<$$.reg<<","<<atoi($2)+1<<endl;
		sonuc<<"\tli $t"<<$$.reg<<","<<atoi($2)+1<<endl;$$.type=0;}
	| SAYI AZALT {$$.reg=hafizadan_al();cout<<"\tli $t"<<$$.reg<<","<<$1<<endl;
		sonuc<<"\tli $t"<<$$.reg<<","<<$1<<endl;$$.type=0;}
	| SAYI ARTTIR {$$.reg=hafizadan_al();cout<<"\tli $t"<<$$.reg<<","<<$1<<endl;
		sonuc<<"\tli $t"<<$$.reg<<","<<$1<<endl;$$.type=0;}
	| DEGIL factor {cout<<"\tseq $t"<<$2.reg<<",$t"<<$2.reg<<",$zero"<<endl;
		sonuc<<"\tseq $t"<<$2.reg<<",$t"<<$2.reg<<",$zero"<<endl;$$ = $2;}
	| KARAKTER {$$.reg=hafizadan_al();cout<<"\tli $t"<<$$.reg<<","<<int($1[1])<<endl;sonuc<<"\tli $t"<<$$.reg<<","<<int($1[1])<<endl;$$.type=1;}
	//type 1 char demek. $1[1] aslında biz bunu string gibi alıyoruz o yüzden [1] diyerek sadece o charı aldık 
	//not bu char array değil sadece bir kaarakter için

//burada print içi değil
artrazlt : AZALT ID { if(type_map.find(string($2))!=type_map.end()){
					arttir_azalt($2,1,$$.reg=hafizadan_al(),false,'-');$$.type=type_map[string($2)]; strcpy(temp, $2);}
					else {yyerror("Degisken tipi bildirilmemis");}}
	| ARTTIR ID {if(type_map.find(string($2))!=type_map.end()){
						arttir_azalt($2,1,$$.reg=hafizadan_al(),false,'+');$$.type=type_map[string($2)]; strcpy(temp, $2);}
						else {yyerror("Degisken tipi bildirilmemis");}}
	| ID AZALT { if(type_map.find(string($1))!=type_map.end()){
				arttir_azalt($1,2,$$.reg=hafizadan_al(),false,'-');$$.type=type_map[string($1)]; strcpy(temp, $1);}
			else {yyerror("Degisken tipi bildirilmemis");}}
	| ID ARTTIR {if(type_map.find(string($1))!=type_map.end()){
		arttir_azalt($1,2,$$.reg=hafizadan_al(),false,'+');$$.type=type_map[string($1)]; strcpy(temp, $1);}
		else {yyerror("Degisken tipi bildirilmemis");}}

p_artrazlt : AZALT ID {if(type_map.find(string($2))!=type_map.end()){
					 arttir_azalt($2,1,$$.reg=hafizadan_al(),true,'-');$$.type=type_map[string($2)]; strcpy(temp, $2); }
					 else {yyerror("Degisken tipi bildirilmemis");}}
	| ARTTIR ID {if(type_map.find(string($2))!=type_map.end()){
							arttir_azalt($2,1,$$.reg=hafizadan_al(),true,'+');$$.type=type_map[string($2)]; strcpy(temp, $2);}
							else {yyerror("Degisken tipi bildirilmemis");}}
	| ID AZALT {if(type_map.find(string($1))!=type_map.end()){
							arttir_azalt($1,2,$$.reg=hafizadan_al(),true,'-');$$.type=type_map[string($1)]; strcpy(temp, $1);}
							else {yyerror("Degisken tipi bildirilmemis");}}
	| ID ARTTIR {if(type_map.find(string($1))!=type_map.end()){
								arttir_azalt($1,2,$$.reg=hafizadan_al(),true,'+');$$.type=type_map[string($1)]; strcpy(temp, $1);}
								else {yyerror("Degisken tipi bildirilmemis");}}

temp_id : ID {Node n = h_yukle($1,0,0,0);$$.reg=n.reg;$$.type=n.type;}
	| ID KOSELISOLPAR r_ifade KOSELISAGPAR {Node n = h_yukle($1,$3.type,$3.reg,1);$$.reg=n.reg;$$.type=n.type;}
%%

//yacc fonksiyonu grammer hatası tespiti için burada derleme olmuyor direk syntaxt hatası der.
void yyerror(char const* msg)
{
	fprintf(stderr,"Hata : %s , %d. satirda \n",msg,yylineno);
}
int main(){
	
	sonuc.open("assembly.asm");
	cout<<".text"<<endl<<".globl main"<<endl<<"main:"<<endl;sonuc<<".text"<<endl<<".globl main"<<endl<<"main:"<<endl;
	//C kodunu parse et; Hata varsa result 1 yoksa 0 döner.
	int result = yyparse();
	//memory'i boşalt
	for(int i=0;i<1000;i++)
		hafiza[i]=0;
	//Sonlandır
	cout<<"\tli $v0,10\n\tsyscall"<<endl;	sonuc<<"\tli $v0,10\n\tsyscall"<<endl;	
	cout<<"\n.data\n"; sonuc<<"\n.data\n";
	data();
	
	if(result == 0)
	{ 	
		fprintf(stderr,"#Program sozdizimsel olarak gecerlidir\n");sonuc<<"#Program sozdizimsel olarak gecerlidir"<<endl;
	}
	else{
		fprintf(stderr,"#syntax hatalari algilandi\n");sonuc<<"#syntax hatalari algilandi"<<endl; 
	}

	sonuc.close();  
	return result;
}

/* 
			Yöntemler
	1: azalt ID, ARTTIR ID  ++a, --a
	2: ID azalt, ID ARTTIR a++, a--; 
		sembol ++ , --
*/

//Burada olan type flag mantığı ileride belki float eklersek diye t
//O yüzden gerekli tip eklenince lazım olucak
////id: id(parse olarak) , tipi: type 0 int yada 1char olur, reg: reg olan t0 t1 ,0,0,0 ,, dizi ise index.type r ifade  ve flag 1 olur
void atama(string id,int tipi,int reg,int index_type,int offset_location,int flag)
{
	//Yukarda zaten kontolü koyduk ama yinede kalsın ilerisi için
	if(type_map.find(id)==type_map.end()){
		yyerror("#Bu degisken tipi belirtilmemis");
		sonuc<<"#Bu degisken tipi belirtilmemis"<<endl;
		return;
	}
	//char dizi yok veya başka veri tipinde
	if(flag==1 && index_type!=0){
		yyerror("#tam sayi olmali");
		sonuc<<"#tam sayi olmali"<<endl;
		return;
	}
	//gerekli
	int temp_type = type_map[id];
	char degisken[id.length()+1]; 
	strcpy(degisken,id.c_str());
		//dizi değilse 
	if(flag==0){
		if(temp_type==0){
			cout<<"\tsw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tsw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;
		}
		else{
			cout<<"\tsb $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tsb $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;
		}
		
	}
	//diziyse
	else	{
		int temp = hafizadan_al();
		int temp2 = hafizadan_al();
		//base adres alınır
		cout<<"\tla $t"<<temp<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tla $t"<<temp<<","<<degisken<<"_degiskeni"<<endl;
		// size temp int se 4 char sa 1 olmalı
		//cout<<"\tli $t"<<temp2<<","<<size[temp_type]<<endl;sonuc<<"\tli $t"<<temp2<<","<<size[temp_type]<<endl;
		cout<<"\tmul $t"<<offset_location<<",$t"<<offset_location<<","<<size[temp_type]<<endl;sonuc<<"\tmul $t"<<offset_location<<","<<size[temp_type]<<endl;
		cout<<"\tadd $t"<<temp<<",$t"<<temp<<",$t"<<offset_location<<endl;sonuc<<"\tadd $t"<<temp<<",$t"<<temp<<",$t"<<offset_location<<endl;
		if(temp_type == 0){//storeword
			cout<<"\tsw $t"<<reg<<",($t"<<temp<<")"<<endl;sonuc<<"\tsw $t"<<reg<<",($t"<<temp<<")"<<endl;
		}
		else{//storebyte
			cout<<"\tsb $t"<<reg<<",-1($t"<<temp<<")"<<endl;sonuc<<"\tsb $t"<<reg<<",-1($t"<<temp<<")"<<endl;
		}

		hafizadan_sil(temp);
		hafizadan_sil(temp2);
		hafizadan_sil(offset_location);
		}
		hafizadan_sil(reg);
		if( temp_type == 1 && tipi== 0 || temp_type == 0 && tipi== 1 )
			yyerror("#Tip eslesmedi!");
}

void arttir_azalt(char *degisken,int yontem,int reg, bool print, char sembol)
{	
	if(yontem ==2 && print ){
		cout<<"\tli $v0, 1"<<endl;sonuc<<"\tli $v0, 1"<<endl; 
		cout<<"\tlw $a0"<<","<<degisken<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tlw $a0"<<","<<degisken<<endl<<"\tsyscall"<<endl;
	}
	cout<<"\tlw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tlw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;
	//+
	if(sembol == '+'){
		cout<<"\taddi $t"<<reg<<","<<"$t"<<reg<<",1"<<endl;sonuc<<"\taddi $t"<<reg<<","<<"$t"<<reg<<",1"<<endl;
	}	//-	
	else{
		cout<<"\taddi $t"<<reg<<",$t"<<reg<<",-1"<<endl;sonuc<<"\taddi $t"<<reg<<",$t"<<reg<<",-1"<<endl;
	}
	cout<<"\tsw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;sonuc<<"\tsw $t"<<reg<<","<<degisken<<"_degiskeni"<<endl;
	if(yontem == 1 && print ){
		cout<<"\tli $v0, 1"<<endl;sonuc<<"\tli $v0, 1"<<endl; 
		cout<<"\tlw $a0"<<","<<degisken<<"_degiskeni"<<endl<<"\tsyscall"<<endl;sonuc<<"\tlw $a0"<<","<<degisken<<endl<<"\tsyscall"<<endl;
	}
	//en son sil
	hafizadan_sil(reg);
}
//hafıdan ilk boş olan yeri al
//programın en sonunda boşaltılacaktır.
int hafizadan_al()
{
	for(int i=0;i<1000;i++)
	{
		if(hafiza[i]==0)
		{
			hafiza[i]=1;
			return i;
		}
	}
    return 0;		
}

//a. indeksi boşalt 
void hafizadan_sil(int a)
{
	hafiza[a]=0;
	return;
}

//hepsini boşalt
void hafizayi_bosalt()
{
	for(int i=0;i<1000;i++)
		hafiza[i]=0;
}

// Aritmatik işlemlerin hepsi
// t1 + t2 <= 1 || (t1==1 && t2==1 float ekliyceksek ileride else if şartı bu olmalı
// diğer veri tipleri için n.type değiştirilmeli yerine göre
Node islemler(int reg,int reg2,string islem,int t1,int t2)
{
	Node n;
	n.reg = reg;	
	char temp;
	if( t1 == 1){
		cout<<"\t#char tipi icin islem yapılıyor"<<endl;sonuc<<"\t#char tipi icin islem yapılıyor"<<endl;
	}
	if(t1==t2){ 
		//ilk karakter alındığı için, || yerine | case içeride  bitwise yok .
		switch(islem[0]){
			case '+':
				cout<<"\tadd $t"<<reg<<",$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tadd $t"<<reg<<",$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '-':
				cout<<"\tsub $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tsub $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '*':
				cout<<"\tmult $t"<<reg<<","<<"$t"<<reg2<<"\n\tmflo,$t"<<reg<<endl;sonuc<<"\tmult $t"<<reg<<","<<"$t"<<reg2<<"\n\tmflo,$t"<<reg<<endl;
				break;
			case '/':
				cout<<"\tdiv $t"<<reg<<","<<"$t"<<reg2<<"\n\tmflo,$t"<<reg<<endl;sonuc<<"\tdiv $t"<<reg<<","<<"$t"<<reg2<<"\n\tmflo,$t"<<reg<<endl;
				break;
			case '%':
				cout<<"\tdiv $t"<<reg<<","<<"$t"<<reg2<<"\n\tmfhi,$t"<<reg<<endl;sonuc<<"\tdiv $t"<<reg<<","<<"$t"<<reg2<<"\n\tmfhi,$t"<<reg<<endl;
				break;
			case '=':
				cout<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '>':
				if(islem.length()>1){
					cout<<"\tsge $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tsge $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				}
				else{
					cout<<"\tsgt $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tsgt $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				}
				break;
			case '<':
				if(islem.length()>1){
					cout<<"\tsle $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tsle $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				}
				else{
					cout<<"\tslt $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tslt $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				}
				break;
			case '!':
				//değil olarak eşit değil mi vs de
				if(islem.length() > 1){
					cout<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
					cout<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$zero"<<endl;sonuc<<"\tseq $t"<<reg<<","<<"$t"<<reg<<",$zero"<<endl;
				}//bitwise olarak
				else{
					cout<<"\tnot $t"<<reg2<<","<<"$t"<<reg2<<endl;sonuc<<"\tnot $t"<<reg2<<","<<"$t"<<reg2<<endl;
				}
				break;
			case '|':
				cout<<"\tor $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tor $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '&':
				cout<<"\tand $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\tand $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
			case '^':
				cout<<"\txor $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;sonuc<<"\txor $t"<<reg<<","<<"$t"<<reg<<",$t"<<reg2<<endl;
				break;
		}
		n.type = 0;
	}
	else
	{
		yyerror("Uyumsuz tip!!");sonuc<<"Uyumsuz tip!!"<<endl;
	}
	hafizadan_sil(reg2);
	return n;
}

//node f temp id için işlemler cıkar temp_id
//flag = 1 dizi ,  dizi için ve normal yoldan iki tane yolladık
Node h_yukle(char* a,int offset_type,int offset_location,int flag)
{
	Node n;
	if(type_map.find(string(a))==type_map.end())
	{
		yyerror("Bilinmeyen tipte degisken");sonuc<<"Bilinmeyen tipte degisken"<<endl;
		return n;
	}
	n.type=type_map[string(a)];
	if(flag==0)
	{
		n.reg=hafizadan_al();
		cout<<"\tlw $t"<<n.reg<<","<<a<<"_degiskeni"<<endl;sonuc<<"\tlw $t"<<n.reg<<","<<a<<"_degiskeni"<<endl;
	}
	else
	{
		if(offset_type != 0)
		{
			yyerror("Dizin integer tipte olmalı");sonuc<<"Dizin integer tipte olmalı"<<endl;
			return n;
		}
		int temp,temp2;
		temp=hafizadan_al();
		temp2=hafizadan_al();
		cout<<"\tla $t"<<temp<<","<<a<<"_degiskeni"<<endl;sonuc<<"\tla $t"<<temp<<","<<a<<"_degiskeni"<<endl;
		temp2=hafizadan_al();
		cout<<"\tli $t"<<temp2<<","<<size[n.type]<<endl;sonuc<<"\tli $t"<<temp2<<","<<size[n.type]<<endl;
		cout<<"\tmult $t"<<offset_location<<","<<"$t"<<temp2<<endl;sonuc<<"\tmult $t"<<offset_location<<","<<"$t"<<temp2<<endl;
		cout<<"\tmflo $t"<<offset_location<<endl;sonuc<<"\tmflo $t"<<offset_location<<endl;
		cout<<"\tadd $t"<<temp<<","<<"$t"<<temp<<",$t"<<offset_location<<endl;sonuc<<"\tadd $t"<<temp<<","<<"$t"<<temp<<",$t"<<offset_location<<endl;
		n.reg=hafizadan_al();
		cout<<"\tlw $t"<<n.reg<<",($t"<<temp<<")"<<endl;sonuc<<"\tlw $t"<<n.reg<<",($t"<<temp<<")"<<endl;
		hafizadan_sil(offset_location);
		hafizadan_sil(temp);
		hafizadan_sil(temp2);
	}
	return n;
}

void data(){
	for(map<string,int>::iterator it = type_map.begin(); it != type_map.end(); ++it) {
		string a = it->first;
		string b = a;
		char degisken[a.length()+1]; 
		if (size_map.find(a)==size_map.end())
		{
			strcpy(degisken,a.c_str());
			//int' se 
			if(type_map[b]==0){
				cout<<degisken<<"_degiskeni: .word 0"<<endl;sonuc<<degisken<<"_degiskeni: .word 0"<<endl;
			}
				
			//char sa
			if(type_map[b]==1){
				cout<<degisken<<"_degiskeni: .byte 0"<<endl;sonuc<<degisken<<"_degiskeni: .word 0"<<endl;
			}
				
		}	
		else{
			strcpy(degisken,a.c_str());
			if(type_map[b]==0){
				cout<<degisken<<"_degiskeni: .word 0:"<<size_map[b]<<endl;sonuc<<degisken<<"_degiskeni: .word 0:"<<size_map[b]<<endl;
			}
			if(type_map[b]==1){
				cout<<degisken<<"_degiskeni: .byte 0:"<<size_map[b]<<endl;sonuc<<degisken<<"_degiskeni: .byte 0:"<<size_map[b]<<endl;
			}	
		}
	}
}