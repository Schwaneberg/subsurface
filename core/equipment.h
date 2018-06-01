#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "dive.h"

#ifdef __cplusplus
extern "C" {
#endif


enum equipment_type_t {
	GENERIC_EQUIPMENT_TYPE,
	SUIT_EQUIPMENT_TYPE,
	CYLINDER_EQUIPMENT_TYPE
};

typedef struct
{
	volume_t size;
	pressure_t workingpressure;
} cylinder_parameters_t;

/*typedef struct
{
	struct gasmix gasmix;
	pressure_t start, end, sample_start, sample_end;
	depth_t depth;
	bool manually_added;
	volume_t gas_used;
	volume_t deco_gas_used;
	enum cylinderuse cylinder_use;
	bool bestmix_o2;
	bool bestmix_he;
} gas_use_t;*/

typedef struct {
	uint32_t uuid;
	enum equipment_type_t equipment_type;
	char *description;
	char *serial;
	char *purchase_info;
	timestamp_t last_service;
	char *service_technician;
	uint32_t service_interval_month;
	uint32_t service_interval_dives;
	char *notes;
	cylinder_parameters_t *cylinder_parameters;
	bool is_rental;
} equipment_t;

typedef struct equipment_container_t {
	equipment_t *eq;
	int32_t packed_weight;
	struct equipment_container_t *next;
} equipment_container_t;

#ifdef __cplusplus
}
#endif

#endif // EQUIPMENT_H

