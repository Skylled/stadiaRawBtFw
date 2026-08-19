// 600d38c8  FUN_600d38c8  size=112 bytes
// --- callers ---
//   60059560 FUN_60059560
// --- callees ---
//   60101b0c FUN_60101b0c
//   601019da FUN_601019da
//   600d3888 FUN_600d3888
//   600d38a8 FUN_600d38a8
//   60101aa4 FUN_60101aa4
//   60101ac8 FUN_60101ac8
//   6010138c FUN_6010138c


void FUN_600d38c8(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  undefined1 auStack_240 [272];
  int local_130;
  int local_12c;
  int local_128;
  
  uVar4 = 0;
  FUN_600d3888(auStack_240);
  FUN_600d38a8(&local_130);
  puVar5 = param_2;
  while( true ) {
    iVar1 = local_128;
    puVar5 = puVar5 + 1;
    if (*param_2 <= uVar4) break;
    uVar6 = *puVar5;
    iVar2 = FUN_60101ac8(&local_130);
    if (iVar2 != 0) {
      uVar3 = FUN_60101b0c(uVar6,(int)uVar6 >> 0x1f,local_128 + local_130,local_12c - local_128);
      FUN_601019da(&local_130,uVar3,iVar1,0x5d);
    }
    uVar4 = uVar4 + 1;
  }
  FUN_60101aa4(auStack_240,param_1,&local_130);
  FUN_6010138c(param_3,auStack_240);
  return;
}


