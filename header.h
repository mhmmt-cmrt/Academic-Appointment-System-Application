#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
// created by muhammet Cömert.
/*ogrenci ve akademisyen siniflarinin ortak ozelliklerinin bulundugu
ve bu ozelliklerin miras alindigi base classtir. ad soyad e posta ve
telefon numaralarini setler ve cagrildigi yere bu deger. dondurur*/

class CKisi
{
public:

	CKisi();
	CKisi(string strAd, string strSoyad,
		string strEPosta, string strTelefonNo);

	void setAdi(string strAd);         // ad setleniyor
	string getAdi();
	void setSoyadi(string strSoyad);   //soyad setleniyor
	string getSoyadi();
	void setEposta(string strEPosta);  // e posta setleniyor
	string getEposta();
	void setTelefonNo(string telefon); // telefon setleniyor
	string getTelefonNo();

private:
	string m_strAd;                //uye degiskenler tanimlaniyor
	string m_strSoyad;
	string m_strEposta;
	string m_strTelefonNo;
};

/*Ogrenci sinifi kisi sinifindan miras alir ve kisi sinifina ek
olarak ogrenci sýnýfinda olmasi gereken degiskenler ve bu
degiskenlerin set ve get fonksiyonlari tanimlanmaktadir.*/

class COgrenci : public CKisi
{
public:
	COgrenci();  // varsayilan kurucu
	COgrenci(string strAd, string strSoyad, string ogrNo, string bolum,
		string strEPosta, string strTelefonNo, string kayitYili);

	void setBolum(string bolum);         //bolumu setler
	string getBolum();                   //bolumu dondurur
	void setKayitYili(string kayitYili); //kayit yilini setler
	string getKayitYili();				 //kayit yilini dondurur.
	void setOgrNo(string ogrNo);         //ogr no yu setler
	string getOgrNo();                   // ogr no yu dondurur

private:

	string m_strBolum;          // uye degiskenler tanimlaniyor
	string m_strKayitYili;
	string m_strOgrNo;

};

/*Akademisyen sinifi kisi sinifindan miras alir yani is a baglantisi
vardir. kisi sinina ek olarak akdemisyen sinifinda olmasi gereken
degiskenler ve bu degiskenlerin set ve get fonksiyonlarý tanýmlanir*/

class CAkademisyen :public CKisi
{
public:
	CAkademisyen();  // varsayilan kurucu
	CAkademisyen(string strAd, string strSoyad, string strSicilNo,
		string strAnaBilimDali, string strEPosta,
		string strTelefonNo, string strUnvan);
	 
	void setAnaBilimDali(string strAnaBilimDali); // anabilimdali set
	string getAnaBilimDali();                     // anabil.da.dondurur
	void setUnvan(string strUnvan);               // unvan setlenir
	string getUnvan();                            // unvan dondurur
	void setSicilNo(string strSicilNo);           // sicilno setlenir
	string getSicilNo();                          // sicilno dondurur.

private:

	string m_strAnaBilimDali;          // uye degiskenler tanimlaniyor
	string m_strUnvan;
	string m_strSicilNo;
};

/*tarihin gun ay yil degerlerini araliklarini dikkate alarak
ayarlayan donduren ve ozel durumlarini kontrol eden siniftir.
ozel durum olarak ay sonlari ve 4 yýlda bir olan 29 subat
tarihi kontrol ediliyor.*/

class CTarih
{
public:

	CTarih();                                  // varsayilan kurucu
	CTarih(int iGn, int iAy, int iSene);

	void setGun(int iGn);                      // gunu ayarlar
	int getGun();                              // gunu dondurur
	void setAy(int iAy);                       // ayi ayarlar
	int getAy();                               // ayi dondurur
	void setYil(int iSene);                    // Yili ayarlar
	int getYil();                              // Yili dondurur
	int gunKontrol(int iGn) const;
	static const int skiYildakiAySayisi = 12;  // ay sayisini týtar

private:

	int m_iYil;                      //uye degiskenler tanimlaniyor.
	int m_iGun;
	int m_iAy;

	//30 veya 31 gun araligini ve subat(4 yilda bir olusan)
	//ozel durumunu kontrol eder
};

/*saat islemlerinin yapildigi siniftir. saat dakika ve saniyenim
get ve set uye fonksiyonlarinin yani sira dakika ekle fonksiyonu
ile girilen saate alinan dk cinsinden verileri ekler ve donusum
fonksiyonu ile de saat bilgisini saniye bilgisine donusturur.*/

class CSaat
{

	friend ostream& operator << (ostream& output, const CSaat& s);
	friend istream& operator >> (istream& input, CSaat& s);

public:

	CSaat(int, int, int);            // parametreli kurucu          
	void dakikaEkle(int iDakika);    //saate dakika ekler
	CSaat operator + (int iDakika);  //operator asýrý yukleme
	int donusum(const CSaat& saat);  //saati saniyeye cevirir
	void setSaat(int iSaat);         //saati ayarlar
	int getSaat();                   //saai dondurur
	void setDakika(int iDakika);     //dakikayi ayarlar
	int getDakika();                 //dakikayi dondurur
	void setSaniye(int iSaniye);     //saniyeyi ayrlar
	int getSaniye();                 //saniyeyi dondurur

private:
	int m_iSaat;             //uye degiskenler tanimlaniyor
	int m_iDakika;
	int m_iSaniye;
};

/*ekleme silme listeleme guncelleme ve sorgulama gibi islemlerin
yapildigi islem sinifidir. icerisinde diger siniflarin nesnelerini
bulundurur. diger siniflara erisim icin compozisyon kullanir.
randevu sorgulama ve cakisma durumlarini kontrol eder.*/

class COperasyonelClass
{
public:
	COperasyonelClass();                 //varsayilan kurucu
	void ekle(int iPivotDeger);          //dosyaya veri ekler
	//istenilen dosyadan istenilen satir verisini  siler 
	void sil(string strDosyaAdi, int iPivotDeger);
	void listele(int iPivotDeger);       // dosya listeler
	//istenilen dosyadan istenilen satirdaki sutunu gunceller
	void guncelle(string strDosyaAdi, int iPivotDeger);
	void randevuSorgula();  //randevunun varligini sorgular
	//cakismanin olup olmadigini sorgular
	int  randevuKontrol(string, string, string, int, int);

private:
	/*diger siniflarin set ve get fonksiyonlarina erisip
	kullanmak ve ayni zamanda islemleri gerceklestirmek
	icin kullanacagi siniflarin nesnesini private olarak tanimlar*/
	CSaat saat, girSaatBasFound, girSaatBitFound, //saat nesneleri
		dosSaatBasFound, dosSaatBitFound;
	COgrenci ogr;                              // ogrenci nesnesi
	CAkademisyen akd;                          //akademisyen nesnesi
	CTarih tarih;                              //tarih nesnesi
};

void islemSecme(int, int);
