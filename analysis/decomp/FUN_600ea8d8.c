// 600ea8d8  FUN_600ea8d8  size=610 bytes
// --- callers ---
//   600eafdc FUN_600eafdc
//   600eb7ce FUN_600eb7ce
//   600eb156 FUN_600eb156
//   600eaba4 FUN_600eaba4
// --- callees ---
//   600e9746 FUN_600e9746
//   600ea89c FUN_600ea89c
//   600ea8ba FUN_600ea8ba
//   600e972c FUN_600e972c


void FUN_600ea8d8(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_240 [68];
  undefined1 auStack_1fc [68];
  undefined1 auStack_1b8 [68];
  undefined1 auStack_174 [68];
  undefined1 auStack_130 [68];
  undefined1 auStack_ec [68];
  undefined1 auStack_a8 [68];
  undefined1 auStack_64 [68];
  
  iVar4 = param_3 + 0x44;
  iVar5 = param_3 + 0x88;
  iVar3 = param_2 + 0x88;
  iVar2 = param_2 + 0x44;
  if (*(int *)(param_1 + 0xc0) == 0) {
    FUN_600e9746(param_1,auStack_1b8);
    FUN_600e9746(param_1,auStack_174,iVar4);
    FUN_600e9746(param_1,auStack_130,auStack_174);
    FUN_600e9746(param_1,auStack_ec,iVar5);
    FUN_600ea89c(param_1,auStack_a8,param_3,auStack_174);
    FUN_600e9746(param_1,auStack_a8);
    FUN_600ea8ba(param_1,auStack_a8,auStack_a8,auStack_1b8);
    FUN_600ea8ba(param_1,auStack_a8,auStack_a8,auStack_130);
    FUN_600ea89c(param_1,auStack_a8,auStack_a8);
    FUN_600e9746(param_1,auStack_64,auStack_ec);
    FUN_600e972c(param_1,auStack_64,param_1 + 0x38);
    FUN_600ea89c(param_1,auStack_64,auStack_64,auStack_1b8);
    FUN_600ea89c(param_1,auStack_64,auStack_64,auStack_1b8);
    FUN_600ea89c(param_1,auStack_64,auStack_64,auStack_1b8);
    FUN_600e9746(param_1,param_2,auStack_64);
    FUN_600ea8ba(param_1,param_2,param_2,auStack_a8);
    FUN_600ea8ba(param_1,param_2,param_2,auStack_a8);
    FUN_600ea89c(param_1,iVar3,iVar4,iVar5);
    FUN_600e9746(param_1,iVar3,iVar3);
    FUN_600ea8ba(param_1,iVar3,iVar3,auStack_174);
    FUN_600ea8ba(param_1,iVar3,iVar3,auStack_ec);
    FUN_600ea89c(param_1,auStack_130,auStack_130);
    FUN_600ea89c(param_1,auStack_130,auStack_130);
    FUN_600ea89c(param_1,auStack_130,auStack_130);
    FUN_600ea8ba(param_1,iVar2,auStack_a8,param_2);
    FUN_600e972c(param_1,iVar2,iVar2,auStack_64);
    puVar1 = auStack_130;
  }
  else {
    FUN_600e9746(param_1,auStack_240,iVar5);
    FUN_600e9746(param_1,auStack_1fc,iVar4);
    FUN_600e972c(param_1,auStack_1b8,param_3,auStack_1fc);
    FUN_600ea8ba(param_1,auStack_174,param_3,auStack_240);
    FUN_600ea89c(param_1,auStack_130,param_3,auStack_240);
    FUN_600ea89c(param_1,auStack_ec,auStack_130);
    FUN_600ea89c(param_1,auStack_130,auStack_130,auStack_ec);
    FUN_600e972c(param_1,auStack_a8,auStack_174,auStack_130);
    FUN_600e9746(param_1,param_2,auStack_a8);
    FUN_600ea89c(param_1,auStack_64,auStack_1b8);
    FUN_600ea89c(param_1,auStack_64,auStack_64);
    FUN_600ea89c(param_1,auStack_ec,auStack_64);
    FUN_600ea8ba(param_1,param_2,param_2,auStack_ec);
    FUN_600ea89c(param_1,auStack_240,auStack_1fc,auStack_240);
    FUN_600ea89c(param_1,auStack_174,iVar4,iVar5);
    FUN_600e9746(param_1,iVar3,auStack_174);
    FUN_600ea8ba(param_1,iVar3,iVar3,auStack_240);
    FUN_600ea8ba(param_1,iVar2,auStack_64,param_2);
    FUN_600ea89c(param_1,auStack_1fc,auStack_1fc);
    FUN_600e9746(param_1,auStack_1fc);
    FUN_600e972c(param_1,iVar2,auStack_a8,iVar2);
    FUN_600ea89c(param_1,auStack_1fc,auStack_1fc);
    puVar1 = auStack_1fc;
  }
  FUN_600ea8ba(param_1,iVar2,iVar2,puVar1);
  return;
}


