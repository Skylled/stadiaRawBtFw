// 600ca1f8  tasks__600ca1f8  size=124 bytes
// src: tasks.c
// --- callers ---
//   600cacb8 timers__600cacb8
//   600cc178 FUN_600cc178
//   600ca4ac tasks__600ca4ac
// --- callees ---
//   600c9fd8 FUN_600c9fd8
//   600ca0fc FUN_600ca0fc
//   601016a2 FUN_601016a2


/* WARNING: Removing unreachable block (ram,0x600ca230) */
/* src: tasks.c */

undefined4
tasks__600ca1f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,int param_7)

{
  undefined4 local_24 [2];
  
  if (param_6 == 0) {
    FUN_601016a2(DAT_600ca278,599,DAT_600ca274);
  }
  if (param_7 == 0) {
    FUN_601016a2(DAT_600ca278,600,DAT_600ca274);
    local_24[0] = 0;
  }
  else if (param_6 == 0) {
    local_24[0] = 0;
  }
  else {
    *(int *)(param_7 + 0x30) = param_6;
    *(undefined1 *)(param_7 + 0xc9) = 2;
    FUN_600ca0fc(param_1,param_2,param_3,param_4,param_5,local_24,param_7);
    FUN_600c9fd8(param_7);
  }
  return local_24[0];
}


