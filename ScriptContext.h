//todo includes

//rebuild roblox scriptcontext context
//something with vftable
class ScriptContext {
    public:
     int* Getglobalstate(int offset, int multiplier, int offset2)
        {
            typedef int* (__thiscall *_GetGlobalState)(ScriptContext*, int,int,int);
            return *(DWORD *)(this + offset * multiplier + offset2 ) - (this + offset * multiplier + offset2);
        }
};
