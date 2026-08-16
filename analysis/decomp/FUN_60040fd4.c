// 60040fd4  FUN_60040fd4  size=74 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_60040fd4(uint param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  func_0x6004bf6c(&uStack_18,*_DAT_60041020,0);
  uVar3 = (param_1 & 0xffff) >> 8;
  if ((param_1 & 0xff) < 0x20) {
    uVar2 = (1 << (param_1 & 0xff)) - 1;
  }
  else {
    uVar2 = 0xffffffff;
  }
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar5 = *(uint *)(_DAT_60041024 + ((param_1 & 0xffffff) >> 0x10) * 4);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  func_0x6004c2f4(&uStack_18,_DAT_60041024,uVar3,uVar4);
  return uVar5 >> uVar3 & uVar2;
}


