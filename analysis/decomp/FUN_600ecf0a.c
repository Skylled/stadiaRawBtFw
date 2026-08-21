// 600ecf0a  FUN_600ecf0a  size=62 bytes
// --- callers ---
//   600ed248 FUN_600ed248
//   600ed12a FUN_600ed12a
//   600ed22a FUN_600ed22a
// --- callees ---
//   600ecef4 FUN_600ecef4


undefined4 FUN_600ecf0a(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int local_1c;
  uint uStack_18;
  
  local_1c = param_2;
  uStack_18 = param_3;
  iVar1 = FUN_600ecef4(param_1,&local_1c,param_5,param_4,param_1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar4 = param_5 - 1;
    do {
      uVar3 = param_4 >> 8;
      *(char *)(local_1c + uVar4) = (char)param_3;
      uVar4 = uVar4 - 1;
      param_3 = param_3 >> 8 | param_4 << 0x18;
      param_4 = uVar3;
    } while (uVar4 < param_5);
    uVar2 = 1;
    if (param_3 != 0 || uVar3 != 0) {
      *(undefined1 *)(param_1 + 0xd) = 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}


