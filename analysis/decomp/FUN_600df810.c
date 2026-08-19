// 600df810  FUN_600df810  size=104 bytes
// --- callers ---
//   60077948 FUN_60077948
//   600df878 FUN_600df878
//   600820d8 FUN_600820d8
//   6004cbf0 device_info__6004cbf0
// --- callees ---
//   600dfb00 FUN_600dfb00
//   60081ea4 FUN_60081ea4
//   600dfadc FUN_600dfadc


undefined4 FUN_600df810(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  int *piVar4;
  undefined1 auStack_28 [4];
  int local_24;
  undefined4 *local_18;
  
  iVar1 = FUN_600dfadc(auStack_28);
  do {
    if (iVar1 == 0) {
      return 1;
    }
    if ((*(byte *)(local_24 + 4) & 0xf) == 8) {
      for (piVar4 = (int *)*local_18; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[2]) {
        pcVar2 = *(code **)(*piVar4 + 4);
        if (pcVar2 == (code *)0x0) {
          iVar1 = *(int *)(*piVar4 + 8);
          if ((*(byte *)(iVar1 + 4) & 0xc0) == 0x80) {
            piVar3 = piVar4 + 1;
          }
          else {
            piVar3 = (int *)piVar4[1];
          }
          iVar1 = FUN_60081ea4(param_1,iVar1,piVar3);
        }
        else {
          iVar1 = (*pcVar2)(param_1,piVar4);
        }
        if (iVar1 == 0) {
          return 0;
        }
      }
    }
    else {
      iVar1 = FUN_60081ea4(param_1);
      if (iVar1 == 0) {
        return 0;
      }
    }
    iVar1 = FUN_600dfb00(auStack_28);
  } while( true );
}


