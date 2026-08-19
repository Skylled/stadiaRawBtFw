// 600dfca0  FUN_600dfca0  size=40 bytes
// --- callers ---
//   60083080 remote_device_db__60083080
//   6006c340 remote_device_db__6006c340
// --- callees ---
//   600653f0 FUN_600653f0


int FUN_600dfca0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)FUN_600653f0();
  iVar3 = 0;
  while( true ) {
    if (piVar1[1] == iVar3) {
      return 0;
    }
    piVar2 = *(int **)(*piVar1 + iVar3 * 4);
    if (*(char *)(*piVar2 + 8) == '\v') break;
    iVar3 = iVar3 + 1;
  }
  return piVar2[1];
}


