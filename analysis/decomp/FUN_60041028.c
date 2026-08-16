// 60041028  FUN_60041028  size=100 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60041028(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uStack_18;
  uint uStack_14;
  
  if ((int)(param_1 << 7) < 0) {
    uVar5 = (param_1 & 0xffff) >> 8;
    uStack_18 = param_1;
    uStack_14 = param_2;
    func_0x6004bf6c(&uStack_18,*_DAT_6004108c,0);
    if ((param_1 & 0xff) < 0x20) {
      uVar3 = (1 << (param_1 & 0xff)) - 1;
    }
    else {
      uVar3 = 0xffffffff;
    }
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    puVar4 = (uint *)(((param_1 & 0xffffff) >> 0x10) * 4 + 0x400ac000);
    *puVar4 = *puVar4 & ~(uVar3 << uVar5);
    *puVar4 = (param_2 & uVar3) << uVar5 | *puVar4;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar2 & 1) == 1);
    }
    func_0x6004c2f4(&uStack_18,uVar2);
  }
  return;
}


