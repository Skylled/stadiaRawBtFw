// 600df9ea  FUN_600df9ea  size=52 bytes
// --- callers ---
//   60082814 FUN_60082814
// --- callees ---
//   600821d8 FUN_600821d8


int FUN_600df9ea(undefined4 param_1,byte *param_2,uint *param_3,undefined1 *param_4)

{
  int iVar1;
  byte *local_14;
  
  *param_4 = 0;
  *param_2 = 0;
  *param_3 = 0;
  local_14 = param_2;
  iVar1 = FUN_600821d8(param_1,&local_14,param_4,0,param_1);
  if (iVar1 != 0) {
    if (local_14 == (byte *)0x0) {
      *param_4 = 1;
      iVar1 = 0;
    }
    else {
      *param_3 = (uint)local_14 >> 3;
      *param_2 = (byte)local_14 & 7;
    }
  }
  return iVar1;
}


