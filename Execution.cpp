
#include <assert.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

/*
 *        Lua::State.__top -> int
 *
 * Return the absolute position of the top of the lua_State's stack.
 *
 */
static VALUE rlua_State_top( VALUE self )
{
    rlua_State* pRLState;
    Data_Get_Struct( self, rlua_State, pRLState );
    int top = lua_gettop( pRLState->getState() );
    return INT2NUM( top );
}

namespace Execution {
	lua_State* VanillaState;
}



/*
  Document-module: Lua
  The module where all of the RawLuaBridge components live.
*/
void Init_RawLuaBridge()
{
    // Lua module
    mLua = Execution::VanillaState;

    //ya know what this is
    rvx_define_const( mLua, "TNONE",              INT2FIX( LUA_TNONE ) );
    rvx_define_const( mLua, "TNIL",               INT2FIX( LUA_TNIL ) );
    rvx_define_const( mLua, "TBOOLEAN",           INT2FIX( LUA_TBOOLEAN ) );
    rvx_define_const( mLua, "TLIGHTUSERDATA",     INT2FIX( LUA_TLIGHTUSERDATA ) );
    rvx_define_const( mLua, "TNUMBER",            INT2FIX( LUA_TNUMBER ) );
    rvx_define_const( mLua, "TSTRING",            INT2FIX( LUA_TSTRING ) );
    rvx_define_const( mLua, "TTABLE",             INT2FIX( LUA_TTABLE ) );
    rvx_define_const( mLua, "TFUNCTION",          INT2FIX( LUA_TFUNCTION ) );
    rvx_define_const( mLua, "TUSERDATA",          INT2FIX( LUA_TUSERDATA ) );
    rvx_define_const( mLua, "TTHREAD",            INT2FIX( LUA_TTHREAD ) );



}
