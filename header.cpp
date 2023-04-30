#include<iostream>
#include<string>
#include<fstream>
#include<array>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include "header.h"

using namespace std;


//  created by muhammet Cömert

CKisi::CKisi()  // varsayilan kurucu
{
}
CKisi::CKisi(string strAd, string strSoyad, string strEPosta,
	string strTelefonNo)         // parametreli kurucu
{
	setAdi(strAd);                       //ismi ayrlar
	setSoyadi(strSoyad);                 //soyismi ayarlar
	setEposta(strEPosta);                //eposta ayarlar
	setTelefonNo(strTelefonNo);          //telefon ayarlar
}

void CKisi::setAdi(string strAd)         //ismi ayrlar
{
	this->m_strAd = strAd;
}

string CKisi::getAdi()                   //ismi dondurur
{
	return this->m_strAd;
}

void CKisi::setSoyadi(string strSoyad)   //soyismi ayarlar
{
	this->m_strSoyad = strSoyad;
}

string CKisi::getSoyadi()                //soyismi dondurur
{
	return this->m_strSoyad;
}

void CKisi::setEposta(string strEPosta)  //eposta ayarlar
{
	this->m_strEposta = strEPosta;
}

string CKisi::getEposta()                //eposta dondurur
{
	return this->m_strEposta;
}

void CKisi::setTelefonNo(string strTelefonNo) //telefon ayarlar
{
	this->m_strTelefonNo = strTelefonNo;
}

string CKisi::getTelefonNo()                  //telefon dondurur
{
	return this->m_strTelefonNo;
}
//------------------------kisi.cpp sonu------------------------------

COgrenci::COgrenci()                       //varsayilan kurucu
{
}

COgrenci::COgrenci(string strAd, string strSoyad, string strOgrNo,
	string strBolum, string strEPosta, string strTelefonNo,
	string strKayitYili)           // parametreli kurucu

//ortak degiskenleri miras aldigi sinifin kurucusuyla ayarlar
	: CKisi(strAd, strSoyad, strEPosta, strTelefonNo)
{
	setBolum(strBolum);                       // bolum ayarlanir
	setKayitYili(strKayitYili);               // kayityili ayarlanir
	setOgrNo(strOgrNo);                       // ogrenciNo ayarlanir
}

void COgrenci::setBolum(string strBolum)       // bolum ayarlanir
{
	this->m_strBolum = strBolum;
}

string COgrenci::getBolum()                    // bolum dondurur
{
	return this->m_strBolum;
}

void COgrenci::setKayitYili(string strKayitYili)// kayityili ayarlanir
{
	this->m_strKayitYili = strKayitYili;
}

string COgrenci::getKayitYili()                 // kayityili dondurur
{
	return this->m_strKayitYili;
}

void COgrenci::setOgrNo(string strOgrNo)        // ogrenciNo ayarlanir
{
	this->m_strOgrNo = strOgrNo;
}

string COgrenci::getOgrNo()                     // ogrenciNo dondurur
{

	return this->m_strOgrNo;
}

//---------------------------------ogrenci.cpp sonu----------------------------------------

CAkademisyen::CAkademisyen()    //varsayilan kurucu
{
}

CAkademisyen::CAkademisyen(string strAd, string strSoyad,
	string strSicilNo, string strAnaBilimDali, string strEPosta,
	string strTelefonNo, string strUnvan)  // parametreli kurucu

	//ortak degiskenleri miras aldigi sinifin kurucusuyla ayarlar
	: CKisi(strAd, strSoyad, strEPosta, strTelefonNo)
{
	setAnaBilimDali(strAnaBilimDali);       //Anabilimdali ayarlanir
	setUnvan(strUnvan);                     //unvan ayarlanir
	setSicilNo(strSicilNo);                 //sicilno ayarlanir
}

void CAkademisyen::setAnaBilimDali(string strAnaBilimDali)
{
	this->m_strAnaBilimDali = strAnaBilimDali;
}

string CAkademisyen::getAnaBilimDali()       //Anabilimdali dondurur
{
	return this->m_strAnaBilimDali;
}

void CAkademisyen::setUnvan(string strUnvan)      //unvan ayarlanir
{
	this->m_strUnvan = strUnvan;
}

string CAkademisyen::getUnvan()                    //unvan dondurur
{
	return this->m_strUnvan;
}

void CAkademisyen::setSicilNo(string strSicilNo)  //sicilno ayarlanir
{
	this->m_strSicilNo = strSicilNo;
}

string CAkademisyen::getSicilNo()                 //sicilno dondurur
{
	return this->m_strSicilNo;
}
//--------------------------Akademisyen.cpp sonu-------------------------------------------

CTarih::CTarih()                            //varsayilan kurucu
{
	this->m_iAy = 1;
	this->m_iGun = 1;
	this->m_iYil = 2010;
}

CTarih::CTarih(int iGn, int iAy, int iSene)  //parametreli kurucu
{
	setGun(iGn);
	setAy(iAy);
	setYil(iSene);
}

void CTarih::setGun(int iGn)                    //gun u ayarlar
{
	int deger;
	deger = gunKontrol(iGn);    //ozel durumlari kontrol eder
	if (deger == 1)
	{
		this->m_iGun = iGn;
	}
	else
	{
		cout << "1-12 arasinda bir degerle tekrar deneyin" << endl;
	}
}

int CTarih::getGun()                                // gun u dondurur   
{
	return this->m_iGun;
}

void CTarih::setAy(int iAy)                         // ay i ayarlar
{
	if (iAy > 0 && iAy <= skiYildakiAySayisi)
	{
		this->m_iAy = iAy;
	}
	else
	{
		cout << "ay degeri 1-12 arasinda olmalidir\n";
	}
}

int CTarih::getAy()                                  // ay i dondurur
{
	return this->m_iAy;
}

void CTarih::setYil(int iSene)                       // Yil i ayarlar
{
	this->m_iYil = iSene;
}

int CTarih::getYil()                                 // Yili dondurur
{
	return this->m_iYil;
}

int CTarih::gunKontrol(int iGn) const  // iGn degerini kontrol eder. 
{
	int i = 0, j = 0;
	// ay sonlarinin degerlerini tutan dizi
	static const array<int, skiYildakiAySayisi + 1> aydakiMaxGun =
	{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	// iGn degeri 1-31 arasinda olmali
	if (iGn > 0 && iGn <= aydakiMaxGun[this->m_iAy])
	{
		i++;
	}

	// 29 subat ozel durumu kontrol ediliyor.
	if (this->m_iAy == 2 && iGn == 29 && (this->m_iYil % 400 == 0 ||
		(this->m_iYil % 4 == 0 && this->m_iYil % 100 != 0)))
	{
		j++;
	}
	if ((i + j) >= 1)
	{
		return 1;
	}

	else
	{
		return 0;
		cout << "29 subat takvimi için hatali veri girildi\n" << endl;
		cout << "Gun degerine varsayilan olarak 0 atandi\n" << endl;
	}
}
//-------------------------date.cpp sonu-----------------------------

CSaat::CSaat(int iSaat = 00, int iDakika = 00, int iSaniye = 00)
{
	setSaat(iSaat);              // saat dakika ve saniye ayarlanir
	setDakika(iDakika);
	setSaniye(iSaniye);
}

void CSaat::dakikaEkle(int iDakika)     //saate dakika ekler
{
	int aDakika = this->m_iDakika + iDakika;
	this->m_iDakika = aDakika % 60;
	this->m_iSaat += aDakika / 60;
	this->m_iSaat = this->m_iSaat % 24;
}

CSaat CSaat::operator + (int iDakika) //saate dakika ekler aþ.yuk. ile
{
	CSaat s2;
	int aDakika = this->m_iDakika + iDakika;
	s2.m_iDakika = aDakika % 60;
	s2.m_iSaat = this->m_iSaat + aDakika / 60;
	s2.m_iSaat = s2.m_iSaat % 24;
	s2.m_iSaniye = this->m_iSaniye;
	return s2;
}

int CSaat::donusum(const CSaat& saat)  //saati saniyeye cevirir
{
	int d2 = saat.m_iSaniye;
	d2 += saat.m_iDakika * 60;
	d2 += saat.m_iSaat * 3600;

	return d2;
}

ostream& operator << (ostream& output, const CSaat& s)
{
	//oprator asiri yukleme yapiliyor

	output << s.m_iSaat << ":"
		<< s.m_iDakika << ":"
		<< s.m_iSaniye << endl;

	return output;
}

istream& operator >> (istream& input, CSaat& s)
{
	//oprator asiri yukleme yapiliyor

	input >> s.m_iSaat >> s.m_iDakika >> s.m_iSaniye;

	return input;
}

void CSaat::setSaat(int iSaat)                 //saati ayarlar
{
	if (iSaat >= 0 && iSaat < 24)
	{
		this->m_iSaat = iSaat;
	}
	else
		cout << "hatali saat degeri girildi\n";
}

int CSaat::getSaat()                           //saai dondurur
{
	return this->m_iSaat;
}

void CSaat::setDakika(int iDakika)             //dakikayi ayarlar
{
	if (iDakika >= 0 && iDakika < 60)
	{
		this->m_iDakika = iDakika;
	}
	else
		cout << "hatali dakika degeri girildi\n";
}

int CSaat::getDakika()                         //dakikayi dondurur
{
	return this->m_iDakika;
}

void CSaat::setSaniye(int iSaniye)             //saniyeyi ayrlar
{
	if (iSaniye >= 0 && iSaniye < 60)
	{
		this->m_iSaniye = iSaniye;
	}
	else
		cout << "hatali saniye degeri girildi\n";
}

int CSaat::getSaniye()                         //saniyeyi dondurur
{
	return this->m_iSaniye;
}
//----------------------------saat.cpp sonu--------------------------

/*ekleme fonk kullanicidan verileri alir bu verileri setler ve
daha sonra ekrana yazdirir. pivot degerine gore hangi dosyaya
ekleme islemi yapilacagini belirleriz pivot 1,2 ogrenci ve
akademisyen icin olurken pivot 3 randevu sistemi icindir.*/

COperasyonelClass::COperasyonelClass()   //varsayilan kurucu
{}

void COperasyonelClass::ekle(int iPivot) //ekleme fonksiyonu
{
	string strVeri;
	if (iPivot == 1 || iPivot == 2)      // birim 1 ve 2 icin ekleme
	{
		if (iPivot == 1)
		{
			cout << "adi: "; cin >> strVeri; ogr.setAdi(strVeri);
			cout << "soyadi: "; cin >> strVeri; ogr.setSoyadi(strVeri);
			cout << "ePosta: "; cin >> strVeri; ogr.setEposta(strVeri);
			cout << "Cep telefon No: "; cin >> strVeri;
			ogr.setTelefonNo(strVeri);

			cout << "ogrenciNo: "; cin >> strVeri;
			ogr.setOgrNo(strVeri);

			cout << "kayit yili: "; cin >> strVeri;
			ogr.setKayitYili(strVeri);

			cout << "bolum: "; cin >> strVeri; ogr.setBolum(strVeri);

			ofstream ofDosya;       //dosya nesnesi olusturuluyor
			ofDosya.open("ogrenci.txt", ios::app); //dosya acma

			ofDosya << left << setw(20) << ogr.getOgrNo()
				<< setw(20) << ogr.getAdi()
				<< setw(20) << ogr.getSoyadi()
				<< setw(20) << ogr.getBolum()
				<< setw(20) << ogr.getKayitYili()
				<< setw(20) << ogr.getEposta()
				<< setw(20) << ogr.getTelefonNo() << endl;

			ofDosya.close(); //dosya kapama
			cout << "\nlistenin son hali \n";
			listele(1);     // ekleme sonrasi tabloyu gosterir
		}
		if (iPivot == 2)
		{
			cout << "adi: "; cin >> strVeri; akd.setAdi(strVeri);
			cout << "soyadi: "; cin >> strVeri; akd.setSoyadi(strVeri);
			cout << "ePosta: "; cin >> strVeri; akd.setEposta(strVeri);
			cout << "Cep telefon No: "; cin >> strVeri;
			akd.setTelefonNo(strVeri);

			cout << "SicilNo: "; cin >> strVeri;
			akd.setSicilNo(strVeri);

			cout << "Unvan: "; cin >> strVeri; akd.setUnvan(strVeri);
			cout << "Anabilim Dali: "; cin >> strVeri;
			akd.setAnaBilimDali(strVeri);

			ofstream ofDosya;  //dosya nesnesi olusturuluyor
			ofDosya.open("akademisyen.txt", ios::app); //dosya acma

			ofDosya << left << setw(20) << akd.getSicilNo()
				<< setw(20) << akd.getAdi()
				<< setw(20) << akd.getSoyadi()
				<< setw(20) << akd.getAnaBilimDali()
				<< setw(20) << akd.getUnvan()
				<< setw(20) << akd.getEposta()
				<< setw(20) << akd.getTelefonNo() << endl;
			ofDosya.close();     //dosya kapama
			cout << "\nlistenin son hali \n";
			listele(2);          // ekleme sonrasi tabloyu gosterir
		}
	}
	if (iPivot == 3)
	{
		int iHour, iMinute, iSure;
		int iGn, iAy, iYl, iCount = 0;
		string  strOgrNo, strSclNo, strTrh;

		cout << "Ogrenci Tablosu" << endl; listele(1);
		cout << "Akademisyen Tablosu" << endl; listele(2);
		cout << "Mevcut Randevu Tablosu" << endl; listele(3);
		cout << "Yukaridaki tablolardan ";
		cout << "yararlanarak randevu kaydinizi olusturun" << endl;

		cout << "Ogrenci No: "; cin >> strVeri; ogr.setOgrNo(strVeri);
		cout << "Akademisyen Sicil No: "; cin >> strVeri;
		akd.setSicilNo(strVeri);

		cout << "Randevu Tarihi(gn ay yil): \n"; cin >> iGn >> iAy >> iYl;
		tarih.setAy(iAy), tarih.setGun(iGn), tarih.setYil(iYl);
		cout << "Baslangic Saati(saat,dakika): \n"; cin >> iHour >> iMinute;
		girSaatBasFound.setSaat(iHour), girSaatBasFound.setDakika(iMinute);
		cout << "Randevu Suresi (dk cinsinden): "; cin >> iSure;
		girSaatBitFound = (girSaatBasFound + iSure);

		/*ogrenci ve sicil no uzerinde rakamlari kullanarak herhangi
		bir islem olmadigindan bu degerleri string yapiyoruz*/

		strOgrNo = ogr.getOgrNo();
		strSclNo = akd.getSicilNo();

		int iBasTopSaniye, iBitTopSaniye;   //saniye ye cevirme
		iBasTopSaniye = saat.donusum(girSaatBasFound);
		iBitTopSaniye = saat.donusum(girSaatBitFound);

		// randevunun cakisma durumu kontrol ediliyor.
		iCount += randevuKontrol(strOgrNo, strSclNo, strTrh,
			iBasTopSaniye, iBitTopSaniye);

		if (iCount == 0)  //donus degeri 0 ise cakisma yoktur
		{
			ofstream ofDosya;  //dosya acmma
			ofDosya.open("randevu.txt", ios::app);

			ofDosya << left << setw(10) << ogr.getOgrNo()
				<< setw(8) << akd.getSicilNo()
				<< right << setfill('0') << setw(2) << tarih.getGun()
				<< "." << setw(2) << tarih.getAy()
				<< "." << tarih.getYil() << "    "
				<< setw(2) << girSaatBasFound.getSaat()
				<< ":" << setw(2) << girSaatBasFound.getDakika()
				<< ":" << setw(2) << girSaatBasFound.getSaniye() << "    "
				<< setw(2) << girSaatBitFound.getSaat() << ":"
				<< setw(2) << girSaatBitFound.getDakika() << ":"
				<< setw(2) << girSaatBitFound.getSaniye() << endl;

			cout << "\nlistenin son hali \n";
			ofDosya.close();   //dosya kapama
			listele(3);        // ekleme sonrasi tabloyu gosterir
		}
		else
		{
			//cakisma tespit edilirse ;
			cout << "Girilen verilere gore sistemde 'TAKVIM "
				<< "CAKISMASI' tespit edilmistir\n"
				<< "Tablodan uygun zaman araligina gore"
				<< "tekrar deneyin\n" << endl;
		}
	}
}
/*silme islemi pivot 1 ve pivot 2 icin benzersiz olan ogr ve sicil
numarasý kullanýlarak yapilirken pivot 3 icin ayni gun ayni
akademisyenden birden fazla randevu alinabildigi icin ogr no sicil no
tarih ve baslangic saatleri kullanicidan alinarak satiri bu degerler
kullanilarak bulup islem gerceklestirilir*/

void COperasyonelClass::sil(string strDosyaAdi, int iPivot)
{
	string strData, strNumara;
	listele(iPivot);   //silinecek verinin oldugu dosyayi listele
	ifstream dosya2;   // dosya nesnesi 
	ofstream dosya3;   // dosya nesnesi 
	dosya2.open(strDosyaAdi, ios::in);  // dosyayi okuma modunda ac
	dosya3.open("deneme.txt", ios::app); // dosyayi yazma modunda ac

	if (iPivot == 1 || iPivot == 2)
	{
		cout << "silmek istediginiz kisinin numarasi : ";
		cin >> strNumara;

		while (dosya2 >> strData)
		{
			if (strData != strNumara)
			{
				dosya3 << left << setw(20) << strData;

				for (int i = 0; i < 6; i++)
				{
					dosya2 >> strData; dosya3 << setw(20) << strData;
				}
			}
			else
			{
				for (int i = 0; i < 6; i++)
				{
					dosya2 >> strData;
				}
			}
			dosya3 << endl;
		}
	}
	if (iPivot == 3)
	{
		//silinecek satiri belirlemek icin kullanilacak degiskenler
		string strDosOgrNo, strDosSicilNo, strDosTrh, StrDosSaatBslngc,
			StrGirSaatBslngc, strGirSicilNo, strGirOgrNo, strGirTrh,
			strDosSaatBts;

		// satir eslestirme icin alinan veriler
		cout << "Girilecek verileri dosyadaki formatlariyla girin\n ";
		cout << "silmek istediginiz kisinin Ogrenci numarasi : ";
		cin >> strGirOgrNo;
		cout << "Ogrencinin randevu aldigi akademisyenin Sicil No: ";
		cin >> strGirSicilNo;
		cout << "Randevu tarihini formatiyla girin: ";
		cin >> strGirTrh;
		cout << "Randevu baslangic saatini formatiyla girin: ";
		cin >> StrGirSaatBslngc;

		while (dosya2 >> strData)  // veri varsa oku
		{
			strDosOgrNo = strData;
			dosya2 >> strData; strDosSicilNo = strData;
			dosya2 >> strData; strDosTrh = strData;
			dosya2 >> strData; StrDosSaatBslngc = strData;
			dosya2 >> strData; strDosSaatBts = strData;

			//okunan satir silincek satirla eslesiyormu kont. ediliyor
			if ((strDosOgrNo == strGirOgrNo) &&
				(strDosSicilNo == strGirSicilNo) &&
				(strGirTrh == strDosTrh) &&
				(StrDosSaatBslngc == StrGirSaatBslngc))
			{
				// eslesme var. okuduklarini dosyaya yazma (bos)
			}
			else
			{
				//silinecek satir degilse dosyaya yaz
				dosya3 << left << setw(15) << strDosOgrNo;
				dosya3 << setw(15) << strDosSicilNo;
				dosya3 << setw(15) << strDosTrh;
				dosya3 << setw(15) << StrDosSaatBslngc;
				dosya3 << setw(15) << strDosSaatBts << endl;;
			}
		}
	}
	dosya2.close();  //dosya kapama
	dosya3.close();  //dosya kapama

	//string den const char* a donusum yapar
	const char* str = strDosyaAdi.c_str();

	remove(str);                      // eski dosyayi silme 
	rename("deneme.txt", str);        // yeni dosya ismini adlandirma

	cout << "listenin son hali \n";
	listele(iPivot);
}

/*pivot degerine gore istenilen dosyayi acar ve verileri consola
setw fonksiyonu ile duzenli olarak siralar*/

void COperasyonelClass::listele(int iPivot) //listeleme yapar.
{
	string strData;
	ifstream ifDosya;
	if (iPivot == 1 || iPivot == 2)
	{
		if (iPivot == 1)    // ogrenci.txt i listeler
		{
			ifDosya.open("ogrenci.txt");
			cout << "--------------------------------------------\n";
			cout << left << setw(10) << "Numara" << setw(12) << "isim"
				<< setw(12) << "soyisim" << setw(20) << "bolum"
				<< setw(15) << "K.Yili" << setw(30) << "E-Posta"
				<< setw(20) << "Telefon No(05+)" << endl;
		}
		if (iPivot == 2)   // akademisyen txt i listeler
		{
			ifDosya.open("akademisyen.txt");
			cout << "--------------------------------------------\n";
			cout << left << setw(10) << "SicilNo" << setw(12) << "isim"
				<< setw(12) << "soyisim" << setw(20) << "Anabilim Dali"
				<< setw(15) << "unvan" << setw(30) << "E-Posta"
				<< setw(20) << "Telefon No(05+)" << endl;
		}
		while (ifDosya >> strData)  // verileri okur
		{
					cout << left << setw(10) << strData;
			ifDosya >> strData; cout << setw(12) << strData;
			ifDosya >> strData; cout << setw(12) << strData;
			ifDosya >> strData; cout << setw(20) << strData;
			ifDosya >> strData; cout << setw(15) << strData;
			ifDosya >> strData; cout << setw(30) << strData;
			ifDosya >> strData; cout << setw(20) << strData;
			cout << endl;
		}
	}
	if (iPivot == 3)    //akademisyen txt i listeler
	{
		ifDosya.open("randevu.txt", ios::app);
		cout << "------------------------------------------------\n";
		cout << left << setw(15) << "Ogrenci No"
			<< setw(15) << "Sicil No"
			<< setw(15) << "Tarih"
			<< setw(15) << "Baslangic"
			<< setw(15) << "Bitis" << endl;

		while (ifDosya >> strData)  // verileri okur
		{
			cout << left << setw(15) << strData;
			ifDosya >> strData; cout << setw(15) << strData;
			ifDosya >> strData; cout << setw(15) << strData;
			ifDosya >> strData; cout << setw(15) << strData;
			ifDosya >> strData; cout << setw(15) << strData;
			cout << endl;
		}
	}
	cout << "----------------------------------------------------\n";
	ifDosya.close();
}
/*guncelleme islemi pivot 1 ve pivot 2 icin benzersiz olan ogr ve sicil
numarasý kullanýlarak yapilirken pivot 3 icin ayni gun ayni
akademisyenden birden fazla randevu alinabildigi icin ogr no sicil no
tarih ve baslangic saatleri kullanicidan alinarak satiri bu degerler
kullanilarak bulup islem gerceklestirilir*/

void COperasyonelClass::guncelle(string strDosyaAdi, int iPivot)
{
	listele(iPivot); int j = 0;

	ifstream ifDosya5;  //okunacak dosya
	ofstream ofDosya6;  //yazilacak dosya
	ifDosya5.open(strDosyaAdi, ios::in);    //dosya acma
	ofDosya6.open("deneme.txt", ios::app);  //dosya acma
	if (iPivot == 1 || iPivot == 2)
	{
		string strNumara, strEskiDeger, strYenideger, strData;
		//kullanicidan girdiler alinir.
		cout << "Guncellenecek kisinin numarasini girin: ";
		cin >> strNumara;
		cout << "Guncellenecek sutunun degerini girin: ";
		cin >> strEskiDeger;
		cout << "Guncellenecek sutunun guncel degerini girin: ";
		cin >> strYenideger;

		while (ifDosya5 >> strData)   // okunacak veri varsa oku
		{

			if (strData == strNumara)
			{
				for (int i = 0; i < 7; i++)
				{
					if (strData == strEskiDeger)  // aranan sutun
					{
						ofDosya6 << left << setw(20) << strYenideger;
					}
					else
					{
						ofDosya6 << left << setw(20) << strData;
					}

					j++;

					if (j != 7)
					{
						ifDosya5 >> strData;
					}
				}
			}
			else
			{
				ofDosya6 << left << setw(20) << strData;
				ifDosya5 >> strData;
				ofDosya6 << left << setw(20) << strData;
				ifDosya5 >> strData;
				ofDosya6 << left << setw(20) << strData;
				ifDosya5 >> strData;
				ofDosya6 << left << setw(20) << strData;
				ifDosya5 >> strData;
				ofDosya6 << left << setw(20) << strData;
				ifDosya5 >> strData;
				ofDosya6 << left << setw(20) << strData;
				ifDosya5 >> strData;
				ofDosya6 << left << setw(20) << strData;
			}
			ofDosya6 << endl;
		}
	}
	else
	{
		string strDosOgrNo, strDosSicilNo, strDosTrh,
			StrDosSaatBslngc, StrGirSaatBslngc, strGirSicilNo,
			strGirOgrNo, strGirTrh, strDosSaatBts, strData,
			strEskiDeger, strYenideger;

		//kullanicidan satir bulma icin degerler aliniyor

		cout << "Guncellemek istediginiz kisinin Ogrenci numarasi : ";
		cin >> strGirOgrNo;
		cout << "Ogrencinin randevu aldigi akademisyenin Sicil No: ";
		cin >> strGirSicilNo;
		cout << "Randevu tarihini dosyadaki formatiyla(.) girin: ";
		cin >> strGirTrh;
		cout << "Randevu baslangic saatini formatiyla(:) girin: ";
		cin >> StrGirSaatBslngc;
		cout << "Guncellenecek eski degeri formatiyla girin: ";
		cin >> strEskiDeger;
		cout << "Guncellenecek yeni degeri formatina  girin: ";
		cin >> strYenideger;

		while (ifDosya5 >> strData)  //veri varsa oku
		{
			strDosOgrNo = strData;
			ifDosya5 >> strData; strDosSicilNo = strData;
			ifDosya5 >> strData; strDosTrh = strData;
			ifDosya5 >> strData; StrDosSaatBslngc = strData;
			ifDosya5 >> strData; strDosSaatBts = strData;

			// satirlar eslesiyor mu?
			if ((strDosOgrNo == strGirOgrNo) &&
				(strDosSicilNo == strGirSicilNo) &&
				(strGirTrh == strDosTrh) &&
				(StrDosSaatBslngc == StrGirSaatBslngc))
			{
				//eski degere guncel degeri ata. 
				if (strDosOgrNo == strEskiDeger)
				{
					strDosOgrNo = strYenideger;
				}
				if (strDosSicilNo == strEskiDeger)
				{
					strDosSicilNo = strYenideger;
				}
				if (strGirTrh == strEskiDeger)
				{
					strGirTrh = strYenideger;
				}
				if (StrDosSaatBslngc == strEskiDeger)
				{
					StrDosSaatBslngc = strYenideger;
				}
				if (strDosSaatBts == strEskiDeger)
				{
					strDosSaatBts = strYenideger;
				}
				//guncellenen satiri yazdir
				ofDosya6 << left << setw(15) << strDosOgrNo;
				ofDosya6 << setw(15) << strDosSicilNo;
				ofDosya6 << setw(15) << strDosTrh;
				ofDosya6 << setw(15) << StrDosSaatBslngc;
				ofDosya6 << setw(15) << strDosSaatBts << endl;

			}
			else
			{
				// satirlar eslesmiyorsa aynen yazdir
				ofDosya6 << left << setw(15) << strDosOgrNo;
				ofDosya6 << setw(15) << strDosSicilNo;
				ofDosya6 << setw(15) << strDosTrh;
				ofDosya6 << setw(15) << StrDosSaatBslngc;
				ofDosya6 << setw(15) << strDosSaatBts << endl;
			}
		}
	}
	ofDosya6.close(); //dosya kapama
	ifDosya5.close(); //dosya kapama

	//string den const char* a donusum yapar
	const char* str = strDosyaAdi.c_str();

	remove(str);
	rename("deneme.txt", str);
	cout << "listenin son hali \n";
	listele(iPivot);
}

//randevu tablosundan Okul-Sicil Numarasina gore kayit sorgular
void COperasyonelClass::randevuSorgula()
{
	string strData, strTarih, strBaslangicSaat, strBitisSaat;
	int iNumara, i = 0, j = 0;

	cout << "Sorgulanacak Kisinin Okul-Sicil Numarasini Girin: ";
	cin >> iNumara;

	ifstream ifDosya;
	ifDosya.open("randevu.txt", ios::app);

	while (ifDosya >> strData)
	{
		ogr.setOgrNo(strData);
		ifDosya >> strData; akd.setSicilNo(strData);
		ifDosya >> strData; strTarih = strData;
		ifDosya >> strData; strBaslangicSaat = strData;
		ifDosya >> strData; strBitisSaat = strData;

		if (ogr.getOgrNo() == (to_string(iNumara))) //ogr icin sorgu
		{
			cout << "----------------------------------------------\n";
			cout << left << setw(15) << "Ogrenci No"
				<< setw(15) << "Sicil No"
				<< setw(15) << "Tarih"
				<< setw(15) << "Baslangic"
				<< setw(15) << "Bitis" << endl;

			i++; //kayit varsa aartir

			cout << left << setw(15) << ogr.getOgrNo()
				<< setw(15) << akd.getSicilNo()
				<< setw(15) << strTarih
				<< setw(15) << strBaslangicSaat
				<< setw(15) << strBitisSaat << endl;
		}
		if (akd.getSicilNo() == (to_string(iNumara))) //akd icin sorgu
		{
			cout << "----------------------------------------------\n";
			cout << left << setw(15) << "Sicil No"
				<< setw(15) << "Ogrenci No"
				<< setw(15) << "Tarih"
				<< setw(15) << "Baslangic"
				<< setw(15) << "Bitis" << endl;

			j++;  //kayit varsa aartir

			cout << left << setw(15) << akd.getSicilNo()
				<< setw(15) << ogr.getOgrNo()
				<< setw(15) << strTarih
				<< setw(15) << strBaslangicSaat
				<< setw(15) << strBitisSaat << endl;
		}
	}
	cout << "----------------------------------------------------\n";
	ifDosya.close();

	if (i == 0 && j == 0)  //kayit bulunamadiysa
	{
		cout << " kisinin randevu kaydi bulunmamaktadir" << endl;
	}
}

/*randevu cakismalarini kontrol eden fonksiyondur*/

int COperasyonelClass::randevuKontrol(string strOgrNo, string strSclNo,
	string strTrh, int iBasTopSaniye, int iBitTopSaniye)
{
	string strData, strDosOgrNo, strDosSclNo, strDosTrh,
		strDosSaatBslngc, strDosSaatBts;
	int iDosSaat, iDosDakakika, iDosSaniye, iDosGun, iDosAy, iDosYil;

	int i = 0, j = 0, k = 0;
	ifstream ifDosya;
	ifDosya.open("randevu.txt", ios::in);

	while (ifDosya >> strData) //veri varsa oku
	{
		strDosOgrNo = strData;
		ifDosya >> strData; strDosSclNo = strData;
		ifDosya >> strData; strDosTrh = strData;
		ifDosya >> strData; strDosSaatBslngc = strData;
		ifDosya >> strData; strDosSaatBts = strData;
		cout << endl;

		//okunan baslangic saati stringi int e cevrilir.
		iDosSaat = atoi(strDosSaatBslngc.substr(0, 2).c_str());
		iDosDakakika = atoi(strDosSaatBslngc.substr(3, 2).c_str());
		iDosSaniye = atoi(strDosSaatBslngc.substr(6, 2).c_str());

		//int e cevrilen veriler saat verisi olarak ayarlanir 
		dosSaatBasFound.setSaat(iDosSaat);
		dosSaatBasFound.setDakika(iDosDakakika);
		dosSaatBasFound.setSaniye(iDosSaniye);

		//okunan bitis saati stringi int e cevrilir.
		iDosSaat = atoi(strDosSaatBts.substr(0, 2).c_str());
		iDosDakakika = atoi(strDosSaatBts.substr(3, 2).c_str());
		iDosSaniye = atoi(strDosSaatBts.substr(6, 2).c_str());

		//int e cevrilen veriler saat verisi olarak ayarlanir
		dosSaatBitFound.setSaat(iDosSaat);
		dosSaatBitFound.setDakika(iDosDakakika);
		dosSaatBitFound.setSaniye(iDosSaniye);

		//ayarlanan saatler saniye cinsine cevirilir 
		int iDosBasTopSaniye = saat.donusum(dosSaatBasFound);
		int iDosBitTopSaniye = saat.donusum(dosSaatBitFound);

		// dosyadaki tarih stringi int e cevrilir
		iDosGun = atoi(strDosTrh.substr(0, 2).c_str());
		iDosAy = atoi(strDosTrh.substr(3, 2).c_str());
		iDosYil = atoi(strDosTrh.substr(6, 4).c_str());

		if (iDosGun == tarih.getGun()) // tarih kontrolu yapilir
		{
			if (iDosAy == tarih.getAy())
			{
				if (iDosYil == tarih.getYil())
				{
					k = 1;
				}
			}

		}

		//girilen saatin dosyadaki saatle cakisma durumu varmi 
		//yokmu kontrol edilir eger varsa sayac artirilir

		if (((strSclNo == strDosSclNo) || (strOgrNo == strDosOgrNo))
			&& (k == 1) && !((iBasTopSaniye < iDosBasTopSaniye)
				&& (iBitTopSaniye < iDosBasTopSaniye)
				|| (iBitTopSaniye > iDosBitTopSaniye)
				&& (iBasTopSaniye > iDosBitTopSaniye)))
		{
			i++;
		}
	}
	return i;
}
//-----------------OperasyonelClass.cpp sonu--------------------------------------
/*islem secme fonksiyonu kullanýcýya sunulan menu secenekleri
üzerinden yapilan secimlere uygun hangi sinifin ve o sinifin hangi
uye fonksiyonunun cagrilagini setlemek icin kullanilir. */
void islemSecme(int brm, int islm)
{
	if (brm == 1)
	{

		COperasyonelClass op;
		switch (islm)
		{
		case 1:
			op.ekle(1);
			break;
		case 2:
			op.sil("ogrenci.txt", 1);
			break;
		case 3:
			op.guncelle("ogrenci.txt", 1);
			break;
		case 4:
			op.listele(1);
			break;
		case 5:
			op.randevuSorgula();
			break;
		}
	}
	if (brm == 2)
	{
		COperasyonelClass op;
		switch (islm)
		{
		case 1:
			op.ekle(2);
			break;
		case 2:
			op.sil("akademisyen.txt", 2);
			break;
		case 3:
			op.guncelle("akademisyen.txt", 2);
			break;
		case 4:
			op.listele(2);
			break;
		case 5:
			op.randevuSorgula();
			break;
		}
	}
	if (brm == 3)
	{
		COperasyonelClass op;
		switch (islm)
		{
		case 1:
			op.ekle(3);
			break;
		case 2:
			op.sil("randevu.txt", 3);
			break;
		case 3:
			op.guncelle("randevu.txt", 3);
			break;
		case 4:
			op.listele(3);
			break;
		}
	}
}
//----------------------islemsecme fonk sonu----------------------------------
