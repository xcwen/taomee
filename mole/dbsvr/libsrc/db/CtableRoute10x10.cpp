/*
 * =====================================================================================
 *
 *       Filename:  CtableRoute10x10.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2007年11月06日 19时52分56秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  xcwen (xcwen), xcwenn@gmail.com
 *        Company:  TAOMEE
 *
 * =====================================================================================
 */
#include "CtableRoute10x10.h"

#include "common.h"
#include "proto.h"
#include "benchapi.h"
	// id_name : 用于id_is_existed方法中
CtableRoute10x10::CtableRoute10x10(mysql_interface * db, const char * db_name_pre,  
		 const char * table_name_pre,const char* id_name )
	: CtableRoute(db, db_name_pre, table_name_pre, id_name )
{

}



char * CtableRoute10x10::get_table_name(uint32_t id)
{

	sprintf (this->db_name,"%s_%01d", this->db_name_pre,id%10 );
	this->db->select_db(this->db_name);
	sprintf (this->db_table_name,"%s_%01d.%s_%01d",
	this->db_name_pre,id%10, this->table_name_pre,(id/10)%10);
	return this->db_table_name;
}

