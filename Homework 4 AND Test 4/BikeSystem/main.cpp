#include "Bike.h"
#include "HelloBike.h"
#include "OfoBike.h"
#include "BikeSystem.h"


int main()
{
	Bike* tempBike = new OfoBike("ofo10", 40,15, 4);
	tempBike->unlock(); //���"unlock ofo10"
	tempBike->unlock(); //��� "fail to unlock ofo10"
	cout << tempBike->lock() << endl; //��� "lock ofo10" "0"
	cout << tempBike->lock() << endl; //��� "ofo10 has been locked" "-1"
	Bike* tempBike2 = new OfoBike("ofobike09",15,55,3); //test ofobike move_to, cost output
	tempBike2->unlock();
	tempBike2->move_to(90, 85);
	cout << tempBike2->lock() << endl;

	BikeSystem bike_system; // test search
	bike_system.add(new OfoBike("ofo05", 30, 60, 9));
	bike_system.add(new HelloBike("hellobike01", "hellobike_elock15", 0, 0, 4));
	bike_system.add(new OfoBike("ofo01", 100, 100, 5));
	bike_system.add(new OfoBike("ofo02", 90, 0, 6));
	bike_system.add(new OfoBike("ofo03", 30, 70, 7));
	bike_system.add(new OfoBike("ofo04", 70, 0, 8));
	int idx1 = bike_system.search("xiaoming", 50, 50, 5);
	// ���ҳɹ������"xiaoming selected ofo05",���� idx1=0
	int idx2 = bike_system.search("xiaohong", 50, 50, 9);
	// ���ҳɹ������"xiaohong selected ofo05",���� idx1=0
	bike_system.unlock_bike(idx1); // �����ɹ������"unlock ofo05"
	bike_system.unlock_bike(idx2); // ����ʧ�ܣ����"fail to unlock ofo05"
	bike_system.ride_record(idx1, 100, 100); // ���"from 30,60 to 100,100"
	bike_system.ride_record(idx1, 100, 80); // ���"from 100,100 to 100,80"
	int cost = bike_system.lock_bike(idx1); //�����ɹ������"lock ofo05"������ cost=7
	cout << cost << endl;
}