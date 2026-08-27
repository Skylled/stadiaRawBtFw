// 600cc29c  FUN_600cc29c  size=48 bytes
// --- callers ---
//   6005e164 FUN_6005e164
//   6005e7e0 bug_report__6005e7e0
//   60100c14 FUN_60100c14
//   600dfc30 FUN_600dfc30
// --- callees ---


ushort FUN_600cc29c(ushort *param_1,byte *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar2 = DAT_600cc2cc;
  pbVar3 = param_2;
  while( true ) {
    uVar1 = *param_1;
    if (pbVar3 == param_2 + param_3) break;
    *param_1 = *(ushort *)(iVar2 + ((uint)*pbVar3 ^ (uint)(uVar1 >> 8)) * 2) ^ uVar1 << 8;
    pbVar3 = pbVar3 + 1;
  }
  return uVar1;
}


