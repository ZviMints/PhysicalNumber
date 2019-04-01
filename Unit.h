#ifndef UNIT_H
#define UNIT_H
namespace ariel {
	class Unit {
	public:
		enum length { KM, M, CM };
		enum time { HOUR, MIN, SEC };
		enum mass { TON, KG, G };
	};
}
#endif
