// 600c1988  FUN_600c1988  size=102 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34


void FUN_600c1988(short param_1,ushort param_2)

{
  int iVar1;
  undefined1 local_d;
  int local_c;
  
  iVar1 = DAT_600c19f0;
  local_c = DAT_600c19f0;
  local_d = 0;
  if (param_2 <= *(ushort *)(DAT_600c19f0 + 0x1fe)) {
    *(ushort *)(DAT_600c19f0 + 0x1fe) = *(short *)(DAT_600c19f0 + 0x1fe) - param_2;
  }
  if (((*(short *)(iVar1 + 0x1fe) == 0) && (*(char *)(iVar1 + 0x200) != '\0')) && (param_1 == 6)) {
    FUN_600c1a34(iVar1,0x17,&local_d);
  }
  return;
}


