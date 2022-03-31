#include "DaThuc.h"
DaThuc::DaThuc()
{
	this->bac = n;
	dt = new DonThuc[n+1];
}
DaThuc::DaThuc(int x)
{
	this->bac = x;
	dt = new DonThuc[x+1];
}
float DaThuc::GiaTri(float x)
{
	float S = 0;
	return S;
}
void DaThuc::Nhap()
{
	int k = 0;
	cout << " Nhap bac da thuc:"; cin >> k;
	bac = k; 
	for (int i = 0; i <= bac; i++)
	{
		cout << "He so thu" << i << ":";
		dt[i].Nhap();
		dt[i].setsomu(k);
		k--;
	}
}
void DaThuc::Xuat()
{
	cout << "Da thuc :" << endl;
	for (int i = 0; i <= bac; i++)
	{
			dt[i].Xuat();
			if (i < bac)
			{
				cout << " + ";
			}
	}
}
DaThuc DaThuc::Cong(DaThuc t,DaThuc p) // gia su khong co ham cong don thuc
{
	DaThuc kq;
	if (p.bac - t.bac >= 0)
	{
		kq.bac = p.bac;
		for (int i = 0; i < p.bac+1; i++)
		{
			kq.dt[i].setheso(p.dt[i].getheso());
			kq.dt[i].setsomu(p.dt[i].getsomu());
			for (int j = 0; j < t.bac+1; j++)
			{
				if (p.dt[i].getsomu() == t.dt[j].getsomu())
				{
					kq.dt[i].setheso(p.dt[i].getheso() + t.dt[j].getheso()); // kq[i] = p[i]+t[i] khi so mu = nhau
					kq.dt[i].setsomu(p.dt[i].getsomu());
				}
				else
					continue;
			}
		}
	}
	else
	{
		kq.bac = t.bac;
		for (int i = 0; i <= t.bac+1; i++)
		{
			kq.dt[i].setheso(t.dt[i].getheso());
			kq.dt[i].setsomu(t.dt[i].getsomu());
			for (int j = 0; j < p.bac+1; j++)
			{
				if (p.dt[j].getsomu() == t.dt[i].getsomu())
				{
					kq.dt[i].setheso(p.dt[j].getheso() + t.dt[i].getheso()); // kq[i] = p[i]+t[i] khi so mu = nhau
					kq.dt[i].setsomu(t.dt[i].getsomu());
				}
				else
					continue;
			}
		}
	}
	return kq;
}
DaThuc DaThuc::Tru(DaThuc t , DaThuc p) // khi co ham tru don thuc
{
	DaThuc kq;
	if (p.bac - t.bac >= 0)
	{
		kq.bac = p.bac;
		for (int i = 0; i < p.bac + 1; i++)
		{
			kq.dt[i].setheso(p.dt[i].getheso());
			kq.dt[i].setsomu(p.dt[i].getsomu());
			for (int j = 0; j < t.bac + 1; j++)
			{
				if (p.dt[i].getsomu() == t.dt[j].getsomu())
				{
					kq.dt[i] = p.dt[i].Tru(t.dt[j]); // kq[i] = p[i]+t[i] khi so mu = nhau
				}
				else
					continue;
			}
		}
	}
	else
	{
		kq.bac = t.bac;
		for (int i = 0; i <= t.bac + 1; i++)
		{
			kq.dt[i].setheso(t.dt[i].getheso());
			kq.dt[i].setsomu(t.dt[i].getsomu());
			for (int j = 0; j < p.bac + 1; j++)
			{
				if (p.dt[j].getsomu() == t.dt[i].getsomu())
				{
					kq.dt[i]= t.dt[i].Tru(p.dt[j]); // kq[i] = p[i]+t[i] khi so mu = nhau
				}
				else
					continue;
			}
		}
	}
	return kq;
}

DaThuc DaThuc::Nhan(DaThuc t, DaThuc p)
{
	DaThuc kq;
	kq.bac = t.bac + p.bac;
	for (int i = 0; i < t.bac + 1; i++)
	{
		kq.dt[i] = t.dt[i].Nhan(p.dt[i]);
		for (int j = 0; j < p.bac + 1; j++)
		{
			kq.dt[t.bac+1+j] = t.dt[i].Nhan(p.dt[j]);
		}
	}
	DaThuc temp = kq.Cong(kq, kq);
	kq = kq.Tru(temp, kq);
	return temp;
}

DaThuc DaThuc::Chia(DaThuc, DaThuc)
{
	return DaThuc();
}
