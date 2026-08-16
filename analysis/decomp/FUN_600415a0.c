// 600415a0  FUN_600415a0  size=60 bytes
// --- callers ---
// --- callees ---


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_600415a0(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (param_1 & 0x1fff) >> 8;
  uVar2 = *(uint *)(&DAT_400fc000 + (param_1 & 0xff));
  *(uint *)(&DAT_400fc000 + (param_1 & 0xff)) =
       ((param_1 & 0x3ffffff) >> 0xd) << uVar1 & (param_2 << uVar1 ^ uVar2) ^ uVar2;
  if (param_1 >> 0x1a != 0x20) {
    do {
    } while ((*(uint *)(_DAT_600415dc + 0x48) & 1 << (param_1 >> 0x1a)) != 0);
  }
  return;
}


