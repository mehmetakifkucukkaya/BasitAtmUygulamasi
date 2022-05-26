#include <iostream>
							// Mehmet Akif Kucukkaya - 21040301063 - 21.05.2022
using namespace std;

class Atm
{
public:
	int bakiye = 0;
	int id, sifre, girilenId, girilenSifre, girilenSifre2, cekilenMiktar, yatirilanMiktar, kalanhak = 3;
	char secim, secilenIslem;
	// Gerekli Fonksiyonlar
	void AnaSayfa()
	{
		cout << "Lutfen asagidaki menuden yapmak istediginiz islemi seciniz: " << endl;
		cout << "l -> Giris yapiniz\nc -> Yeni bir hesap olusturunuz\nq -> Cikis " << endl;
		cin >> secim;

		switch (secim)
		{
		case 'l':
			GirisYap();
			break;
		case 'c':
			HesapOlustur();
			break;
		case 'q':
			CikisYap();
			break;

		default:
			cout << "Gecersiz islem sectiniz " << endl;
			AnaSayfa();
			break;
		}
	}
	void GirisYap()
	{
		cout << "Lutfen musteri numaranizi giriniz: ";
		cin >> girilenId;
		cout << "Lutfen sifrenizi giriniz: ";
		cin >> girilenSifre;

		if (girilenId == id && girilenSifre == sifre)
		{
			cout << "Hosgeldiniz! Sisteme baglandiniz" << endl
				 << endl;
			Islemler();
		}
		else
		{
			cout << "********* GIRIS BASARISIZ OLDU *********" << endl;
			kalanhak--;
			if (kalanhak <= 0)
			{
				cout << "Hesabiniz Bloke Edildi";
			}
			else
			{
				AnaSayfa();
			}
		}
	}
	
	void Islemler()
	{
		cout << "d -> Hesabiniza para yatirin\nw -> Hesabinizdan para cekin\nr -> Bakiye goruntuleyin\no -> Diger islemler\np -> Sifre Degistir\nq ->Cikis" << endl;

		cin >> secilenIslem;

		switch (secilenIslem)
		{
		case 'd':
			ParaYatir();
			break;
		case 'w':
			ParaCek();
			break;
		case 'r':
			BakiyeGoruntule();
			break;
		case 'o':
			DigerIslemler();
			break;
		case 'p':
			SifreDegistir();
			break;
		case 'q':
			CikisYap();
			break;
		}
	}
	void HesapOlustur()
	{
		cout << "Lutfen musteri numaranizi giriniz: ";
		cin >> id;
		cout << "Lutfen sifrenizi numaranizi giriniz: ";
		cin >> sifre;
		cout << "\nTesekkurler! Banka hesabiniz olusturuldu.!" << endl;
		AnaSayfa(); // Anasayfaya geri donmemizi sagliyor.
		
	void CikisYap()
	{
		cout << "Hoscakalin..!" << endl;
	}
	void ParaYatir()
	{
		cout << "Yatirmak istediginiz miktari giriniz: ";
		cin >> yatirilanMiktar;

		bakiye += yatirilanMiktar;
		IslemSonuMesaji();
	}
	void ParaCek()
	{
		cout << "Cekmek istediginiz miktari giriniz: ";
		cin >> cekilenMiktar;

		if (bakiye > cekilenMiktar)
		{
			bakiye -= cekilenMiktar;
			IslemSonuMesaji();
		}
		else
		{
			YetersizBakiyeMesaji();
		}
	}
	void BakiyeGoruntule()
	{
		cout << "Hesap Bakiyeniz: " << bakiye << " TL\n"
			 << endl;
		Islemler();
	}
	void DigerIslemler()
	{
		int islemSecim;
		cout << "1 -> Fatura Islemleri\n2 -> Ehliyet Harci Yatir\n3 -> Bagis\n4 -> Sinav Odemeleri \n"<< endl;
		cin >> islemSecim;

		switch (islemSecim)
		{
		case 1:
			Faturalar();
			break;
		case 2:
			EhliyetHarci();
			break;
		case 3:
			Bagis();
			break;
		case 4:
			SinavOdemeleri();
			break;

		default:
			cout << "Gecersiz islem!" << endl;
			DigerIslemler();
			break;
		}
	}
	void Faturalar()
	{
		int faturaSecim, faturaTutari;

		cout << "Yatirmak istediginiz faturayi seciniz: " << endl;
		cout << "1 -> Telefon\n2 ->Su\n3 ->Elektrik\n4 ->Dogalgaz" << endl;
		cin >> faturaSecim;
		cout << "Fatura tutarini giriniz: ";
		cin >> faturaTutari;

		if (bakiye >= faturaTutari)
		{
			cout << "Faturaniz yatirildi!" << endl;
			bakiye -= faturaTutari;
			IslemSonuMesaji();
		}
		else
		{
			YetersizBakiyeMesaji();
		}
	}
	void EhliyetHarci()
	{
		int ehliyetSecim;
		cout << "Ehliyet sinifini seciniz: " << endl;
		cout << "1 -> A: 710 TL\n2 -> B: 1456 TL" << endl;
		cin >> ehliyetSecim;

		if (ehliyetSecim == 1)
		{
			if (bakiye < 710)
			{
				YetersizBakiyeMesaji();
			}
			else
			{
				cout << "Ehliyet Harciniz Yatirildi!" << endl;
				bakiye -= 710;
				IslemSonuMesaji();
			}
		}
		if (ehliyetSecim == 2)
		{
			if (bakiye < 1456)
			{
				YetersizBakiyeMesaji();
			}
			else
			{
				cout << "Ehliyet Harciniz Yatirildi!" << endl;
				bakiye -= 1456;
				IslemSonuMesaji();
			}
		}
	}
	void Bagis()
	{
		int bagisSecim, bagisTutari;
		cout << "Lutfen bagis yapmak istediginiz kurumu seciniz: " << endl;
		cout << "1 -> AFAD\n2 -> Losev\n3 -> Kizilay\n4 -> Mehmetcik Vakfi" << endl;
		cin >> bagisSecim;
		cout << "Lutfen bagis tutarini giriniz: ";
		cin >> bagisTutari;

		if (bakiye >= bagisTutari)
		{
			cout << "Tebrikler bagisiniz yapildi" << endl;
			bakiye -= bagisTutari;
			IslemSonuMesaji();
		}
		else
		{
			YetersizBakiyeMesaji();
		}
	}
	void SinavOdemeleri()
	{
		int sinavSecim, yks = 230, yds = 115, kpss = 90;
		cout << "Odeme yapmak istediginiz sinavi  seciniz: " << endl;
		cout << "1 -> YKS: 230 TL\n2 ->YDT: 115 TL\n3 ->KPSS: 90 TL\n"
			 << endl;
		cin >> sinavSecim;

		if (sinavSecim == 1 && bakiye >= yks)
		{
			cout << "Sinav odemeniz tamamlanmistir!" << endl;
			bakiye -= yks;
			IslemSonuMesaji();
		}
		else
		{
			YetersizBakiyeMesaji();
		}
	}
	void IslemSonuMesaji()
	{
		char mesajSecim;
		cout << "Baska bir islem yapmak istiyor musunuz ?\n E-H" << endl;
		cin >> mesajSecim;

		if (mesajSecim == 'E' || mesajSecim == 'e')
		{
			Islemler();
		}
		if (mesajSecim == 'H' || mesajSecim == 'h')
		{
			CikisYap();
		}
	}
	void YetersizBakiyeMesaji()
	{
		cout << "Hesabinizda yeterli bakiye bulunmamaktadir!" << endl;
		Islemler();
	}
	void SifreDegistir()
	{
		cout << "Su anki sifrenizi giriniz: ";
		cin >> girilenSifre2;

		if (girilenSifre2 == sifre)
		{
			cout << "Yeni sifrenizi giriniz: ";
			cin >> sifre;

			Islemler();
		}
		else
		{
			cout << "Yanlis Sifre!" << endl;
			Islemler();
		}
	}
};
int main()
{
	Atm atm; // Atm sinifindan atm nesnesini olusturduk.
	cout << "Merhaba! Bankamizin ATM Makinesine Hos geldiniz..." << endl;
	atm.AnaSayfa();
}
