//
//  XFCyclicAnnularFlowLayout.h
//  XFCollectionViewLayout
//
//  Created by YanYi on 2021/4/13.
//


#import <UIKit/UIKit.h>

@class XFCyclicAnnularFlowLayout;

typedef NS_ENUM(NSUInteger, XFCyclicAnnularItemOrientation) {
    XFCyclicAnnularItemOrientationUp,           // 朝上 默认
    XFCyclicAnnularItemOrientationDown,         // 朝下
    XFCyclicAnnularItemOrientationInside,       // 朝内
    XFCyclicAnnularItemOrientationOutside       // 朝外
};

@protocol XFCyclicAnnularFlowLayoutDelegate <NSObject>

// 传入当前组的环绕半径
- (CGFloat)flowLayout:(XFCyclicAnnularFlowLayout *)flowLayout cyclicAnnularRadiusInSection:(NSInteger)section;
// 传入当前组的itemsize
- (CGSize)flowLayout:(XFCyclicAnnularFlowLayout *)flowLayout cyclicAnnularItemSizeAtindexPath:(NSIndexPath *)indexPath;
// 所属组的 弧度范围
- (CGFloat)flowLayout:(XFCyclicAnnularFlowLayout *)flowLayout cyclicAnnularRadianInSection:(NSInteger)section;

@optional
// 元素朝向
- (XFCyclicAnnularItemOrientation)cyclicAnnularItemOrientationInFlowLayout:(XFCyclicAnnularFlowLayout *)flowLyout;
// 是否顺时针 默认顺时针
- (BOOL)flowLayout:(XFCyclicAnnularFlowLayout*)flowLayout cyclicIsClockwiseInSection:(NSInteger)section;


@end

@interface XFCyclicAnnularFlowLayout : UICollectionViewFlowLayout


@property (nonatomic, weak  ) id    <XFCyclicAnnularFlowLayoutDelegate> delegate;
// 每组第一个元素角度
@property (nonatomic, assign) CGFloat               startRadian;

@end
