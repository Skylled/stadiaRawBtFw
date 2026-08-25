// 600fa5c6  FUN_600fa5c6  size=246 bytes
// --- callers ---
//   600be100 FUN_600be100
// --- callees ---
//   600beb20 FUN_600beb20
//   600aa340 FUN_600aa340
//   600be150 FUN_600be150
//   600be558 FUN_600be558
//   600bf5a4 FUN_600bf5a4


void FUN_600fa5c6(int param_1,int param_2)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar4 = (char *)(param_2 + 8 + (uint)*(ushort *)(param_2 + 4));
  pcVar5 = pcVar4 + *(ushort *)(param_2 + 2);
  FUN_600aa340(param_1 + 8,5,0x1e);
  cVar1 = *pcVar4;
  sVar2 = (ushort)(byte)pcVar4[2] + (ushort)(byte)pcVar4[1] * 0x100;
  uVar3 = (ushort)(byte)pcVar4[4] + (ushort)(byte)pcVar4[3] * 0x100;
  pcVar4 = pcVar4 + 5;
  if (pcVar5 < pcVar4 + uVar3) {
    FUN_600bf5a4(param_1,sVar2,4,0);
  }
  else if (cVar1 == '\x04') {
    FUN_600be558(param_2,param_1,sVar2,uVar3,pcVar4,pcVar5);
  }
  else if (cVar1 == '\x06') {
    FUN_600beb20(param_2,param_1,sVar2,uVar3,pcVar4,pcVar5);
  }
  else if (cVar1 == '\x02') {
    FUN_600be150(param_2,param_1,sVar2,uVar3,pcVar4,pcVar5);
  }
  else {
    FUN_600bf5a4(param_1,sVar2,3,0);
  }
  return;
}


