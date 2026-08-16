// 600c15a8  FUN_600c15a8  size=346 bytes
// --- callers ---
//   600c0db4 FUN_600c0db4
//   600c0ed4 FUN_600c0ed4
//   600c1548 FUN_600c1548
//   600c0f04 FUN_600c0f04
//   600c0c84 FUN_600c0c84
//   600c0de4 FUN_600c0de4
//   600c1578 FUN_600c1578
//   600c0f34 FUN_600c0f34
//   600c0e7c FUN_600c0e7c
//   600c0e14 FUN_600c0e14
// --- callees ---
//   600fc302 FUN_600fc302
//   600fc206 FUN_600fc206
//   600c0cb4 FUN_600c0cb4
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600fc380 FUN_600fc380
//   600c1a34 FUN_600c1a34
//   600c0de4 FUN_600c0de4
//   600fbdd0 FUN_600fbdd0
//   600c1578 FUN_600c1578
//   600c0f34 FUN_600c0f34
//   600fc9aa FUN_600fc9aa


void FUN_600c15a8(char *param_1)

{
  int iVar1;
  undefined1 local_12;
  byte local_11;
  byte *local_10;
  int local_c;
  
  iVar1 = DAT_600c1734;
  local_c = DAT_600c1734;
  local_10 = (byte *)(param_1 + 4);
  local_12 = 8;
  local_11 = *(byte *)(DAT_600c1734 + 0x1f2) & 0x7f;
  if ((param_1 == (char *)0x0) || (*param_1 != '\0')) {
    FUN_600c1a34(DAT_600c1734,0x17,&local_12);
  }
  else {
    switch(local_11) {
    case 3:
      *(ushort *)(DAT_600c1734 + 0x1d6) = (ushort)(byte)param_1[5] * 0x100 + (ushort)*local_10;
      local_10 = (byte *)(param_1 + 6);
      FUN_600fc302(iVar1,0);
      break;
    case 4:
      *(ushort *)(DAT_600c1734 + 0x1d6) = (ushort)(byte)param_1[5] * 0x100 + (ushort)*local_10;
      local_10 = (byte *)(param_1 + 6);
      FUN_600fbdd0(iVar1,0);
      break;
    case 5:
      thunk_EXT_FUN_0000b572(DAT_600c1734 + 0x1ea,param_1 + 4,8);
      FUN_600fc380(local_c,0);
      break;
    case 6:
      FUN_600c0cb4(DAT_600c1734,param_1);
      break;
    case 7:
      thunk_EXT_FUN_0000b572(DAT_600c1734 + 0x5d,param_1 + 4,param_1[1]);
      FUN_600c0de4(local_c,0);
      break;
    case 8:
      thunk_EXT_FUN_0000b572(DAT_600c1734 + 0x65,param_1 + 4,param_1[1]);
      FUN_600fc206(local_c,0);
      break;
    case 9:
    case 10:
    case 0xb:
    case 0xc:
      FUN_600c0f34(DAT_600c1734,param_1);
      break;
    case 0xd:
      thunk_EXT_FUN_0000b572(DAT_600c1734 + 0x5d,param_1 + 4,param_1[1]);
      FUN_600c1578(local_c);
      break;
    case 0xe:
      thunk_EXT_FUN_0000b572(DAT_600c1734 + 0x65,param_1 + 4,param_1[1]);
      FUN_600fc9aa(local_c);
    }
  }
  return;
}


