// 60080424  adapter__60080424  size=72 bytes
// src: adapter.h
// --- callers ---
//   600df264 state_machine__600df264
// --- callees ---
//   6010165c FUN_6010165c


/* src: adapter.h */

undefined4 adapter__60080424(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x11c);
  if (cVar1 != -1) {
    if (cVar1 == '\x02') {
      uVar2 = *(undefined4 *)(param_1 + 0x110);
      if (param_2 == 0) {
        param_2 = DAT_6008046c;
      }
      *(int *)(param_1 + 0x110) = param_2;
      return uVar2;
    }
    if (cVar1 == '\x01') {
      uVar2 = *(undefined4 *)(param_1 + 0x118);
      if (param_2 == 0) {
        param_2 = DAT_6008046c;
      }
      *(int *)(param_1 + 0x118) = param_2;
      return uVar2;
    }
  }
  FUN_6010165c(0x28,DAT_60080474,0xce,DAT_60080470,param_4);
  return 0;
}


