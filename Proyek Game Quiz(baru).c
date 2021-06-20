#include<stdio.h>
#include<conio.h> //untuk mengatur interface, ex, getch();
#include<ctype.h> //untuk mengubah input lowercase menjadi uppercase, ex: toupper(getch());
#include<stdlib.h> //untuk membuat funtion yang menggunakan address
#include<string.h> //untuk mengedit isi dari char array
#define NUMBER_OF_STRING 4
#define MAX_STRING_SIZE 40

struct Player//data pemain
{
	char playername[20];
	int age;
	int nohp;
	char bank[20];
	int score;
	float prize;
};
typedef struct Player player;
player p;

//prototype fungsi
void store_score(player p);
void printhasil(player *nilai, int countr);
void show_record();
void reset_score();
void help();
void loaderanim();
int tempscr;

int main()
{
int a,w;
int b = 0;

//welcome screen
welcomescr:
printf("\n\n\t\t\tSelamat Datang di QUIZ GAME!");
printf("\n -------------------------------------------------------------------------");
printf("\n\n\t\t\tProgram ini dikembangkan oleh:\n\n ");

char arr[NUMBER_OF_STRING][MAX_STRING_SIZE] =
{ "			Avisiena Mumtaza - 1906318773",
  "			Harsya Adytia Nugraha - 1906384125",
  "			Rifky Adriandra Hadis - 1906384094"
};

for (w = 0; w < NUMBER_OF_STRING; w++)
{
	printf("%s\n", arr[w]);
}
printf("\t\t\tProyek Dasar Komputer-02");
printf("\n\t\t\tDepartemen Teknik Elektro");
printf("\n\t\t\tFakultas Teknik Universitas Indonesia\n");
printf("\n -------------------------------------------------------------------------");
printf("\n\nTekan 1 lalu enter untuk masuk ke menu utama \n");
scanf("%d", &a);
	while(a == 1)
	{
	int countr,r,r1,count,i,n;
    float score;
    char choice;
   	loaderanim();
   	//menu utama
    mainhome:
    system("cls");
    printf("\t\t\t\tQUIZ GAME\n");
    printf("\n\t\t________________________________________");
    printf("\n\t\t\t    MENU UTAMA ");
    printf("\n\t\t________________________________________");
    printf("\n\t\t > Tekan M untuk memulai game");
    printf("\n\t\t > Tekan S untuk melihat skor tertinggi  ");
    printf("\n\t\t > Tekan R untuk reset skor");
    printf("\n\t\t > Tekan B untuk bantuan            ");
    printf("\n\t\t > Tekan K untuk keluar            ");
    printf("\n\t\t________________________________________\n\n");
    printf("\n\n\t\tMENANGKAN TOTAL HADIAH 200 RIBU RUPIAH!!!");
    choice=toupper(getch());
    if (choice=='S')
	{
		show_record();
		goto mainhome;
	}
    else if (choice=='B')
	{
		help();getch();
		goto mainhome;
	}
	else if (choice=='R')
	{
		reset_score();
		getch();
		goto mainhome;
	}
	else if (choice=='K')
	{
		system("cls");
		//exit screen
		printf("\n\n\t\t\tTerima Kasih!");
		printf("\n -------------------------------------------------------------------------");
		printf("\n\n\t\t\tProgram ini dikembangkan oleh:\n\n ");
		char arr[NUMBER_OF_STRING][MAX_STRING_SIZE] =
		{ "			Avisiena Mumtaza - 1906318773",
 		  "			Harsya Adytia Nugraha - 1906384125",
  		  "			Rifky Adriandra Hadis - 1906384094"
		};
		for (w = 0; w < NUMBER_OF_STRING; w++)
		{
			printf("%s\n", arr[w]);
		}
		printf("\t\t\tProyek Dasar Komputer-02");
		printf("\n\t\t\tDepartemen Teknik Elektro");
		printf("\n\t\t\tFakultas Teknik Universitas Indonesia\n");
		printf("\n -------------------------------------------------------------------------");
		printf("\n\nExiting in 3 second...........>");
		Sleep(3000);
		exit(0);
	}
    else if(choice=='M')
    {
    	system("cls");
 	}
     else
	{
    	printf("\n\nSalah input! Tekan tombol lainnya untuk melanjutkan");
    	getch();
    	goto mainhome;
	}
	
	//player data input
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tMasukkan nama Anda: ");
    scanf("%s", p.playername);
    printf("\t\t\tUsia: ");
    scanf("%d", &p.age);
    printf("\t\t\tMasukkan nomor rekening Anda untuk pengiriman hadiah");
    printf("\n\t\t\tNo. Rekening: ");
    scanf("%d", &p.nohp);
    printf("\t\t\tBank: ");
    scanf("%s", p.bank);

    system("cls");
    //informasi game
    printf("\n ------------------  Halo %s! Selamat Datang Di Quiz Game --------------------------", p.playername);
    printf("\n\n Berikut adalah beberapa hal yang perlu Anda ketahui mengenai game ini:");
    printf("\n -------------------------------------------------------------------------");
    printf("\n >> Terdapat 2 ronde dalam Quiz Game ini, yaitu Warmup Round dan Challenge Round");
    printf("\n >> Di Warmup Round, Anda akan diberikan tiga pertanyaan untuk mengetes pengetahuan");
    printf("\n    umum Anda. Anda dapat lanjut ke Challenge Round jika mampu menjawab 2 pertanyaan.");
    printf("\n    Jika tidak, maka Anda tidak dapat lanjut ke Challenge Round.");
    printf("\n >> Di Challenge Round, terdapat 20 pertanyaan. Pertanyaan berikutnya akan");
    printf("\n    muncul jika Anda dapat menjawab dengan benar. Setiap pertanyaan bernilai Rp10.000.");
    printf("\n    Jika Anda dapat menjawab 20 pertanyaan dengan benar, Anda akan mendapatkan total");
    printf("\n    hadiah sebesar Rp200.000 yang akan ditransfer ke no. rekening Anda.");
    printf("\n >> Anda akan diberikan 4 pilihan untuk menjawab, yaitu A, B, C, dan D.");
    printf("\n\n\t!!!!!!!!!!!!! SEMOGA BERUNTUNG !!!!!!!!!!!!!");
    printf("\n\n\n Tekan Y untuk memulai game!\n");
    printf("\n Tekan tombol lainnya untuk kembali ke menu utama.");
    
	if (toupper(getch())=='Y')
		{
		goto home;
    	}
	else
		{
    goto mainhome;
    system("cls");
    	}

    home:
    system("cls");
    count=0;
    for(i=1;i<=3;i++)
    {
    system("cls");
    r1=i;
	
	//soal warm up mode
	switch(r1)
		{
		case 1:
		printf("Soal 1");
		printf("\n\nManakah yang termasuk angka palindrom?");
		printf("\n\nA.42042\t\tB.101010\n\nC.23232\t\tD.01234");
		if (toupper(getch())=='C')
			{
			printf("\n\nBenar!!!");count++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");
			getch();
			break;
			}
		else
		    {
		    printf("\n\nSalah!!! Jawaban yang benar adalah C.23232");
		    printf("\n\nTekan tombol manapun untuk ke soal selanjutnya");
		    getch();
		    break;
		    }

        case 2:
        printf("Soal 2");
		printf("\n\nLagu Indonesia Raya diciptakan oleh...");
		printf("\n\nA.Kusbini\t\tB.W.R. Supratman\n\nC. L. Manik\t\tD. A. Simanjuntak");
		if (toupper(getch())=='B')
			{
			printf("\n\nBenar!!!");count++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");
			getch();
			break;
			}
		else
			{
			printf("\n\nSalah!!! Jawaban yang benar adalah B. W.R. Supratman");
			printf("\n\nTekan tombol manapun untuk ke soal selanjutnya");
			getch();
			break;
			}

        case 3:
        printf("Soal 3");
		printf("\n\nBinatang khas Indonesia dan hanya ada di Indonesia adalah...");
		printf("\n\nA.Harimau\t\tB.Komodo\n\nC.Kakaktua\t\tD.Gajah");
		if (toupper(getch())=='B')
			{
			printf("\n\nBenar!!!");count++;
			printf("\n\nTekan tombol manapun untuk melanjutkan");
			getch();
			break;
			}
		else
			{
			printf("\n\nSalah!!! Jawaban yang benar adalah B.Komodo");
			printf("\n\nTekan tombol manapun untuk melanjutkan");
			getch();
			break;
			}}}

	if(count>=2)
		{
		goto test;
		}
	else
		{
		system("cls");
		printf("-----------------------------------------------------------------");
		printf("\n\nMaaf Anda belum dapat memainkan game ini. Silakan coba lagi.\n\n");
		printf("-----------------------------------------------------------------");
		printf("\n\nTekan tombol manapun untuk kembali ke menu utama");
		getch();
		goto mainhome;
		}
    test:
    system("cls");
    printf("\n\n\t*** Selamat %s! Anda dapat melanjutkan ke Challenge Round ***", p.playername);
    printf("\n\n\n\n\tTekan P untuk memulai Challenge Round.");
    
	if(toupper(getch())=='p')
		{
		goto game;
		}

	//soal challenge mode
	game:
    countr=0;
	for(i=1;i<=20;i++)
    {
	system("cls");
    r=i;
    switch(r)
		{
		case 1:
		printf ("Soal 1");
		printf("\n\nDi bawah ini nama bulan penanggalan Masehi yang jumlah harinya paling sedikit adalah");
		printf("\n\nA.Januari\t\tB.Febuari\n\nC.Maret\t\t\tD.April");
		if (toupper(getch())=='B')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;getch();
			}
		else
			{
			printf("\n\nSalah!!! Jawaban yang benar adalah B.Febuari");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
			break;
			}

		case 2:
		printf("Soal 2");
		printf("\n\nFlora di Indonesia yang pertama kali ditemukan oleh Sir Thomas Stanford Raffles adalah...");
		printf("\n\nA.Buanga Anggrek\t\tB.Bunga Arnoldi\n\nC.Bunga Tulip\t\t\tD.Bunga Mawar");
		if (toupper(getch())=='B')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
			{
			printf("\n\nSalah!!! Jawaban yang benar adalah B.Bunga Arnoldi");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
			break;
			}

        case 3:
        printf("Soal 3");
		printf("\n\nDi bawah ini adalah negara yang berbatasan langsung dengan wilayah daratan Indonesia, kecuali ");
		printf("\n\nA.Malaysia\t\tB.Timor Leste\n\nC.Papua Nugini\t\tD.Singapura");
		if (toupper(getch())=='D')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
			{
			printf("\n\nSalah!!! Jawaban yang benar adalah D.Singapura");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
			break;
			}

        case 4:
        printf("Soal 4"); 
		printf("\n\nLapisan atmosfer yang berfungsi untuk mencegah radiasi sinar matahari masuk ke bumi adalah...");
		printf("\n\nA.Karbondioksida\t\tB.Oksigen\n\nC.Ozon\t\t\t\tD.Karbon monoksida");
		if (toupper(getch())=='C')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
			{
            printf("\n\nSalah!!! Jawaban yang benar adalah C.Ozon");
            printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
		    goto score;
		    break;
			}

        case 5:
        printf("Soal 5");
		printf("\n\nKerajaan Islam pertama di Nusantara adalah...");
		printf("\n\nA.Kerajaan Demak\t\tB.Kerajaan Pajang\n\nC.Kerajaan Samudra Pasai\tD.Kerajaan Islam");
		if (toupper(getch())=='C')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
		    printf("\n\nSalah!!! Jawaban yang benar adalah C.Kerajaan Samudra Pasai");
		    printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
		    goto score;
		    break;
		    }

		case 6:
		printf("Soal 6");
		printf("\n\nPlanet manakah yang paling panas dalam tata surya?");
		printf("\n\nA.Merkurius\t\tB.Venus\n\nC.Jupiter\t\tD.Mars");
		if (toupper(getch())=='B' )
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah B.Venus");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
		    goto score;
		    break;
			}

        case 7:
        printf("Soal 7");
		printf("\n\nPada tahun berapa Christopher Colombus menemukan dunia baru?");
		printf("\n\nA.1292\t\tB.1390\n\nC.1490\t\tD.1492");
		if (toupper(getch())=='D')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah D.1492");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
		    goto score;
		    break;
			}

        case 8:
        printf("Soal 8");
		printf("\n\nDi negara manakah teh ditemukan");
		printf("\n\nA.China\t\tB.Indonesia\n\nC.Jepang\tD.Turki");
		if (toupper(getch())=='A')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah A.China");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
		    goto score;
		    break;
			}

        case 9:
        printf("Soal 9");
		printf("\n\nOrgan paling besar yang ada di tubuh manusia");
		printf("\n\nA.Otak\t\tB.Paru-Paru\n\nC.Kulit\t\tD.Ginjal");
		if (toupper(getch())=='C')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah C. Kulit");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
		    goto score;
		    break;
			}

        case 10:
        printf("Soal 10");
		printf("\n\nSiapa pelukis yang memotong telinganya sendiri setalah bertengkar?");
		printf("\n\nA.Leonardo Da Vinci\t\tB.Picasso\n\nC.Vincent Van Gogh\t\tD.Bernini");
		if (toupper(getch())=='C')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah C. Vincent Van Gogh");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
			break;
			}
			
		case 11:
        printf("Soal 11");
		printf("\n\nHari Sumpah Pemuda diperingati setiap tanggal...");
		printf("\n\nA.28 November\t\tB.28 September\n\nC.28 Agustus\t\tD.28 Oktober");
		if (toupper(getch())=='D')
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah D. 28 Oktober");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}

        case 12:
        printf("Soal 12");
        printf("\n\nFaktor yang paling menentukan dalam perkembangan ekonomi adalah...");
        printf("\n\nA.Teknologi\t\tB.Permodalan\n\nC.Luasnya pasar\t\tD.SDM");
        if (toupper(getch())=='D')
            {
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
            break;
			}
        else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah D.SDM");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}

        case 13:
        printf("Soal 13");
		printf("\n\nSiapakah penemu telepon?");
		printf("\n\nA.Bell\t\tB.Tesla\n\nC.Edison\t\tD.Dalton");
		if (toupper(getch())=='A' )
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah A.Bell");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}
			
		case 14:
        printf("Soal 14");
		printf("\n\nSungai terpanjang di Indonesia adalah....");
		printf("\n\nA.Mahakam\t\tB.Musi\n\nC.Kapuas\t\tD.Citarum");
		if (toupper(getch())=='C' )
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah C.Kapuas");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}
		
		case 15:
        printf("Soal 15");
		printf("\n\nGangguan pada mata dimana tidak dapat melihat objek yang dekat secara jelas disebut...");
		printf("\n\nA.Hipermetropi\t\tB.Miopi\n\nC.TBC\t\tD.HIV");
		if (toupper(getch())=='A' )
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah A.Hipermetropi");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}
			
		case 16:
        printf("Soal 16");
		printf("\n\nMamalia terbesar di dunia adalah...");
		printf("\n\nA.Gajah\t\tB.Bison\n\nC.Buroq\t\tD.Paus");
		if (toupper(getch())=='D' )
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah D.Paus");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}
		
		case 17:
        printf("Soal 17");
		printf("\n\nSiapakah penulis dari seri novel Harry Potter?");
		printf("\n\nA.Nicholas Sparks\t\tB.JRR Tolkien\n\nC.JK Rowling\t\tD.John Green");
		if (toupper(getch())=='C' )
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah C. JK Rowling");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}
		
		case 18:
        printf("Soal 18");
		printf("\n\nBencana alam apa yang diukur dengan skala Ritcher?");
		printf("\n\nA.Tsunami\t\tB.Tornado\n\nC.Gempa\t\tD.Banjir");
		if (toupper(getch())=='C' )
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah C.Gempa");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}
			
		case 19:
        printf("Soal 19");
		printf("\n\nDimanakah danau terluas di Indonesia berada?");
		printf("\n\nA.Sulawesi\t\tB.Jawa\n\nC.Papua\t\tD.Sumatra");
		if (toupper(getch())=='D' )
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk soal selanjutnya");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah D.Sumatra");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}
		
		case 20:
        printf("Soal 20");
		printf("\n\nCagar alam Ujung Kulon terdapat di provinsi...");
		printf("\n\nA.Bengkulu\t\tB.Aceh\n\nC.Bali\t\tD.Banten");
		if (toupper(getch())=='D' )
			{
			printf("\n\nBenar!!!");countr++;
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			break;
			}
		else
		    {
			printf("\n\nSalah!!! Jawaban yang benar adalah D.Banten");
			printf("\n\nTekan tombol manapun untuk melihat skor Anda");getch();
			goto score;
		    break;
			}
		}}
	//keterangan score
	score:
    system("cls");
    p.score=countr;
	p.prize=countr*10000;
	tempscr=p.score;
	if(p.score>0)
		{
	   printf("\n\n\t\t**************** SELAMAT *****************");
	   printf("\nSelamat %s! Berikut adalah skor dan total hadiah yang Anda dapatkan:",p.playername);
	   printhasil(&p,countr);
	   goto go;
		}

	else if(p.score==0)
		{
		printf("\n\n\t******** MAAF ANDA BELUM BERUNTUNG ********");
	    printf("\n\t\t Terima kasih atas partisipasinya");
		goto go;
		}

	//untuk kembali ke menu utama atau bermain lagi
	go:
	puts("\n\n Tekan Y jika Anda ingin main lagi");
	puts("\n Tekan tombol lainnya jika ingin kembali ke menu utama");
	if (toupper(getch())=='Y')
		{
		goto home;
		}
	else
		{
		store_score(p);
		goto mainhome;
		}}
}
	
void store_score(player p)//fungsi untuk menyimpan score tertinggi
{
	system("cls");
	if(p.score>=tempscr)
	{
		remove("score.txt");
	}
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f%d%s%d",&p.playername,&p.prize,&p.nohp,&p.bank,&p.score);
	fclose(f);
	f=fopen("score.txt","w");
	fprintf(f,"\n%s\n%f\n%d\n%s\n%d",p.playername,p.prize,p.nohp,p.bank,p.score);
	fclose(f);
}

void show_record()//fungsi untuk melihat score tertinggi
{
	system("cls");
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f%d%s%d",&p.playername,&p.prize,&p.nohp,&p.bank,&p.score);
	printf("\n\n\t\t************************* SKOR TERTINGGI **********************************");
	printf("\n\t\t Nama		: %s", p.playername);
	printf("\n\t\t Hadiah   	: Rp%.f", p.prize);
	printf("\n\t\t No. Rek	: %d",p.nohp);
	printf("\n\t\t Bank		: %s",p.bank);
	printf("\n\t\t Skor		: %d", p.score);
	printf("\n\t\t***************************************************************************");
	fclose(f);
	printf("\n\n\t\tTekan tombol manapun untuk kembali ke menu utama");
	getch();
}

void reset_score()//fungsi untuk menghapus data score tertinggi
    {
    char plyr[10] = "Kosong";
    char bnk[10] = "Kosong";
    char choice;
    system("cls");
    printf("Tekan enter untuk reset score");
	int z;
		FILE *f;
		remove("score.txt");
		f=fopen("score.txt","w");
		p.prize = 0;
		p.score = 0;
		p.nohp = 0;
		fprintf(f,"\n%s\n%f\n%d\n%s\n%d",plyr,p.prize,p.nohp,bnk,p.score);
	    fclose(f);
	    return;
	}

void help()//menu bantuan
{
	system("cls");
    printf("\n\n                              BANTUAN");
    printf("\n -------------------------------------------------------------------------");
    printf("\n >> Terdapat 2 ronde dalam Quiz Game ini, yaitu Warmup Round dan Challenge Round");
    printf("\n >> Di Warmup Round, Anda akan diberikan tiga pertanyaan untuk mengetes pengetahuan");
    printf("\n    umum Anda. Anda dapat lanjut ke Challenge Round jika mampu menjawab 2 pertanyaan.");
    printf("\n    Jika tidak, maka Anda tidak dapat lanjut ke Challenge Round.");
    printf("\n >> Di Challenge Round, terdapat 20 pertanyaan. Pertanyaan berikutnya akan");
    printf("\n    muncul jika Anda dapat menjawab dengan benar. Setiap pertanyaan bernilai Rp10.000.");
    printf("\n    Jika Anda dapat menjawab 20 pertanyaan dengan benar, Anda akan mendapatkan total");
    printf("\n    hadiah sebesar Rp200.000 yang akan ditransfer ke no. rekening Anda.");
    printf("\n >> Anda akan diberikan 4 pilihan untuk menjawab, yaitu A, B, C, dan D.");
	printf("\n\n\t*********************SEMOGA BERUNTUNG*********************************");
	printf("\n\nTekan tombol manapun untuk kembali ke menu utama");
}

void printhasil(player *nilai, int countr)//fungsi untuk memperlihatkan score pemain
{
	printf("\nSkor		: %d", nilai->score);
	printf("\nTotal Hadiah	: Rp%.f", nilai->prize);
	printf("\nHadiah akan kami kirimkan ke nomor rekening berikut:");
	printf("\nNo. Rek		: %d", nilai->nohp);
	printf("\nBank		: %s", nilai->bank);
}
	
void loaderanim()//fungsi animasi loading
{
	int x;
	system("cls");
	printf("\n\n\n");
	printf("\t\t\tQUIZ GAME");
	printf("\n\n\n");
	printf("\t\t\tLOADING........");
	printf("\n\n");
	while(x<15)
	{
	Sleep(100);printf("%c",219);x++;
	}
}

//Akhir program
