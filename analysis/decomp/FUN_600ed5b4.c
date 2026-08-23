// 600ed5b4  FUN_600ed5b4  size=122 bytes
// --- callers ---
//   60091330 ec_asn1__60091330
//   60091580 ec_asn1__60091580
//   600868fc FUN_600868fc
// --- callees ---
//   600ed556 FUN_600ed556


undefined4 FUN_600ed5b4(byte *param_1,uint *param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  byte *local_20;
  uint *local_1c;
  
  local_20 = param_1;
  local_1c = param_2;
  iVar1 = FUN_600ed556(param_1,&local_20,2);
  if (iVar1 != 0) {
    *param_2 = 0;
    param_2[1] = 0;
    if (((local_1c != (uint *)0x0) && (-1 < (int)((uint)*local_20 << 0x18))) &&
       ((*local_20 != 0 || ((local_1c < (uint *)0x2 || ((char)local_20[1] < '\0')))))) {
      pbVar2 = local_20;
      while( true ) {
        if (pbVar2 == (byte *)((int)local_1c + (int)local_20)) {
          return 1;
        }
        if (param_2[1] >> 0x18 != 0) break;
        uVar3 = *param_2 << 8;
        uVar4 = param_2[1] << 8 | *param_2 >> 0x18;
        *param_2 = uVar3;
        param_2[1] = uVar4;
        *param_2 = uVar3 | *pbVar2;
        param_2[1] = uVar4;
        pbVar2 = pbVar2 + 1;
      }
    }
  }
  return 0;
}


