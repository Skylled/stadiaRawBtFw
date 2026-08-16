// 600b742c  FUN_600b742c  size=166 bytes
// --- callers ---
//   600b85e4 FUN_600b85e4
//   600b842c FUN_600b842c
//   600b7db8 FUN_600b7db8
// --- callees ---
//   6006e0a4 FUN_6006e0a4
//   6006ddd8 FUN_6006ddd8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006e0bc FUN_6006e0bc
//   6006dcdc FUN_6006dcdc


int FUN_600b742c(int param_1,ushort param_2,ushort param_3,char param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_4 == '\x02') && (uVar2 = FUN_6006e0bc(2), 0x5a < uVar2)) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_6006dcdc(param_4,DAT_600b74d4,0x150);
    if (iVar3 != 0) {
      uVar1 = FUN_6006e0a4(param_4);
      if ((uint)uVar1 < (uint)param_2 + (uint)param_3 + 8) {
        FUN_6006ddd8(iVar3,DAT_600b74d4,0x15c);
        iVar3 = 0;
      }
      else {
        *(ushort *)(iVar3 + 4) = param_2;
        *(ushort *)(iVar3 + 2) = param_3;
        thunk_EXT_FUN_0000b572
                  (iVar3 + 8 + (uint)*(ushort *)(iVar3 + 4),
                   param_1 + 8 + (uint)*(ushort *)(param_1 + 4),param_3);
      }
    }
  }
  return iVar3;
}


