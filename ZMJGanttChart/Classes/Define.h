//
//  Define.h
//  ZMJGanttChart
//
//  Created by Jason on 2018/1/23.
//

#ifndef Define_h
#define Define_h
#import <UIKit/UIKit.h>
#define IOS_VERSION_11_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=11.0)? (YES):(NO))


typedef void(^TouchHandler)(NSSet<UITouch *> *touches, UIEvent *event);

typedef struct ZMJState {
    CGRect  frame;
    CGSize  contentSize;
    CGPoint contentOffset;
} State;

typedef NS_OPTIONS(NSUInteger, ZMJScrollPosition) {
    // The vertical positions are mutually exclusive to each other, but are bitwise or-able with the horizontal scroll positions.
    // Combining positions from the same grouping (horizontal or vertical) will result in an NSInvalidArgumentException.
    ScrollPosition_top                 = 1 << 0,
    ScrollPosition_centeredVertiically = 1 << 1,
    ScrollPosition_bottom              = 1 << 2,
    
    // Likewise, the horizontal positions are mutually exclusive to each other.
    ScrollPosition_left                = 1 << 3,
    ScrollPosition_centeredHorizontally= 1 << 4,
    ScrollPosition_right               = 1 << 5,
};


typedef NS_ENUM(NSInteger, GridStyle_Enum) {
    GridStyle_default = 0,
    GridStyle_none,
    GridStyle_solid,
};

typedef NS_ENUM(NSInteger, BorderStyle_Enum) {
    BorderStyle_None,
    BorderStyle_solid,
};

#pragma mark - Defines
typedef struct ZMJDirect {
    CGFloat left;
    CGFloat right;
    CGFloat top;
    CGFloat bottom;
} Direct;

#define DirectZero ((Direct){0, 0, 0, 0})

typedef struct ZMJRectEdge {
    //top || bottom
    Direct *top;
    Direct *bottom;
    
    //left || right
    Direct *left;
    Direct *right;
} RectEdge;

/**
 DescriptionRectEdgeMake
 @param direction
 UIPopoverArrowDirectionUp = 1UL << 0,
 UIPopoverArrowDirectionDown = 1UL << 1,
 UIPopoverArrowDirectionLeft = 1UL << 2,
 UIPopoverArrowDirectionRight = 1UL << 3,
 UIPopoverArrowDirectionAny = UIPopoverArrowDirectionUp | UIPopoverArrowDirectionDown | UIPopoverArrowDirectionLeft | UIPopoverArrowDirectionRight,
 UIPopoverArrowDirectionUnknown = NSUIntegerMax
 
 @param top Direct.top
 @param left Direct.left
 @param bottom Direct.bottom
 @param right Direct.right
 @return create RectEdge with direction
 */
static inline RectEdge
RectEdgeMake(UIPopoverArrowDirection direction, CGFloat top, CGFloat left, CGFloat bottom, CGFloat right)
{
    RectEdge edge;
    if (direction & UIPopoverArrowDirectionUp) {
        Direct d_top;
        d_top.top   = top;
        d_top.left  = left;
        d_top.bottom= bottom;
        d_top.right = right;
        edge.top = &d_top;
    }
    if (direction & UIPopoverArrowDirectionLeft) {
        Direct d_left;
        d_left.top   = top;
        d_left.left  = left;
        d_left.bottom= bottom;
        d_left.right = right;
        edge.left = &d_left;
    }
    if (direction & UIPopoverArrowDirectionRight) {
        Direct d_right;
        d_right.top   = top;
        d_right.left  = left;
        d_right.bottom= bottom;
        d_right.right = right;
        edge.top = &d_right;
    }
    if (direction & UIPopoverArrowDirectionDown) {
        Direct d_bottom;
        d_bottom.top   = top;
        d_bottom.left  = left;
        d_bottom.bottom= bottom;
        d_bottom.right = right;
        edge.top = &d_bottom;
    }
    return edge;
}

static inline BOOL
RectEdgeEqualToRectEdge(RectEdge rectEdge1, RectEdge rectEdge2)
{
    return
    rectEdge1.top->top == rectEdge2.top->top &&
    rectEdge1.top->left == rectEdge2.top->left &&
    rectEdge1.top->right == rectEdge2.top->right &&
    rectEdge1.top->bottom == rectEdge2.top->bottom &&
    
    rectEdge1.bottom->top == rectEdge2.bottom->top &&
    rectEdge1.bottom->left == rectEdge2.bottom->left &&
    rectEdge1.bottom->right == rectEdge2.bottom->right &&
    rectEdge1.bottom->bottom == rectEdge2.bottom->bottom &&
    
    rectEdge1.left->top == rectEdge2.left->top &&
    rectEdge1.left->left == rectEdge2.left->left &&
    rectEdge1.left->right == rectEdge2.left->right &&
    rectEdge1.left->bottom == rectEdge2.left->bottom &&
    
    rectEdge1.right->top == rectEdge2.right->top &&
    rectEdge1.right->left == rectEdge2.right->left &&
    rectEdge1.right->right == rectEdge2.right->right &&
    rectEdge1.right->bottom == rectEdge2.right->bottom;
}

typedef struct ZMJLayoutAttributes {
    NSInteger startColumn;
    NSInteger startRow;
    NSInteger numberOfColumns;
    NSInteger numberOfRows;
    NSInteger columnCount;
    NSInteger rowCount;
    CGPoint insets;
} LayoutAttributes;

typedef NS_OPTIONS(NSUInteger, ZMJDirection) {
    Direction_vertically   = 1 << 0,
    Direction_horizontally = 1 << 1,
    Direction_both         = Direction_vertically | Direction_horizontally,
};

typedef NS_OPTIONS(NSUInteger, ZMJTableStyle) {
    TableStyle_columnHeaderNotRepeated  = 1 << 0,
    TableStyle_rowHeaderNotRepeated     = 1 << 1,
};

typedef NS_ENUM(NSUInteger, ZMJHeaderStyle) {
    HeaderStyle_none,
    HeaderStyle_columnHeaderStartsFirstRow,
    HeaderStyle_rowHeaderStartsFirstColumn,
};


#endif /* Define_h */
