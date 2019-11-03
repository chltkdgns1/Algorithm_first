#include "Cctv.h"

int main() {
	int n_size;
	int m_size;
	cin >> n_size;
	if (n_size < 1 || n_size>8) {
		return 0;
	}
	cin >> m_size;
	if (m_size < 1 || m_size>8) {
		return 0;
	}
	Cctv *cctv = new Cctv(n_size,m_size);
	if (cctv->InputDataMap() == false) {
		return 0;
	}
	cctv->CctvSearch();
	cctv->PrintMap();
	cout << "total sap count : " << cctv->TotalSap() << endl;
	system("pause");
}